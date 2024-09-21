// Player.cpp

#include "Player.hpp"
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <cstring>

Player::Player()
    : formatCtx(nullptr), codecCtx(nullptr), codec(nullptr),
    packet(nullptr), frame(nullptr), swrCtx(nullptr), audioDevice(0),
    isPlaying(false), isPaused(false), isStopped(false),
    volume(SDL_MIX_MAXVOLUME), samplesPlayed(0) {
    // Initialize channel layouts
    av_channel_layout_default(&inChannelLayout, 0);
    av_channel_layout_default(&outChannelLayout, 0);
}

Player::~Player() {
    stop();
}

bool Player::play(const std::string& filepath) {
    if (isPlaying) {
        stop(); // Stop any existing playback
    }

    // Open audio file
    if (avformat_open_input(&formatCtx, filepath.c_str(),
        nullptr, nullptr) != 0) {
        std::cerr << "Не удалось открыть аудиофайл: "
            << filepath << std::endl;
        return false;
    }

    // Get stream info
    if (avformat_find_stream_info(formatCtx, nullptr) < 0) {
        std::cerr << "Не удалось найти информацию о потоках."
            << std::endl;
        return false;
    }

    // Find first audio stream
    audioStreamIndex = -1;
    for (unsigned int i = 0; i < formatCtx->nb_streams; i++) {
        if (formatCtx->streams[i]->codecpar->codec_type ==
            AVMEDIA_TYPE_AUDIO) {
            audioStreamIndex = i;
            break;
        }
    }

    if (audioStreamIndex == -1) {
        std::cerr << "Не удалось найти аудиопоток." << std::endl;
        return false;
    }

    AVCodecParameters* codecParams =
        formatCtx->streams[audioStreamIndex]->codecpar;

    // Find decoder for audio stream
    codec = avcodec_find_decoder(codecParams->codec_id);
    if (!codec) {
        std::cerr << "Неподдерживаемый кодек." << std::endl;
        return false;
    }

    // Allocate decoder context
    codecCtx = avcodec_alloc_context3(codec);
    if (!codecCtx) {
        std::cerr << "Не удалось выделить контекст декодера."
            << std::endl;
        return false;
    }

    // Copy codec parameters to context
    if (avcodec_parameters_to_context(codecCtx, codecParams) < 0) {
        std::cerr << "Не удалось скопировать параметры декодера."
            << std::endl;
        return false;
    }

    // Open decoder
    if (avcodec_open2(codecCtx, codec, nullptr) < 0) {
        std::cerr << "Не удалось открыть декодер." << std::endl;
        return false;
    }

    // Initialize SDL Audio
    if (!initializeSDL()) {
        std::cerr << "Не удалось инициализировать SDL Audio."
            << std::endl;
        return false;
    }

    // Allocate packet and frame
    packet = av_packet_alloc();
    if (!packet) {
        std::cerr << "Не удалось выделить AVPacket." << std::endl;
        return false;
    }

    frame = av_frame_alloc();
    if (!frame) {
        std::cerr << "Не удалось выделить AVFrame." << std::endl;
        return false;
    }

    // Initialize SwrContext for resampling
    swrCtx = swr_alloc();
    if (!swrCtx) {
        std::cerr << "Не удалось выделить SwrContext." << std::endl;
        return false;
    }

    // Copy input channel layout
    av_channel_layout_default(&inChannelLayout, codecCtx->ch_layout.nb_channels);

    // If input channel layout is unspecified, set default
    if (inChannelLayout.order == AV_CHANNEL_ORDER_UNSPEC ||
        inChannelLayout.nb_channels == 0) {
        av_channel_layout_default(&inChannelLayout,
            codecCtx->ch_layout.nb_channels);
    }

    // Set output channel layout to stereo
    av_channel_layout_uninit(&outChannelLayout);
    av_channel_layout_default(&outChannelLayout, 2);

    // Set options for SwrContext
    if (swr_alloc_set_opts2(&swrCtx,
        &outChannelLayout, AV_SAMPLE_FMT_S16, 44100,
        &inChannelLayout, codecCtx->sample_fmt, codecCtx->sample_rate,
        0, nullptr) < 0) {
        std::cerr << "Не удалось установить параметры SwrContext."
            << std::endl;
        return false;
    }

    // Initialize SwrContext
    if (swr_init(swrCtx) < 0) {
        std::cerr << "Не удалось инициализировать SwrContext."
            << std::endl;
        return false;
    }

    isPlaying = true;
    isPaused = false;
    isStopped = false;
    samplesPlayed = 0;

    // Start decoding and playback threads
    decodeThread = std::thread(&Player::decodingLoop, this);
    playbackThread = std::thread(&Player::playbackLoop, this);

    return true;
}

void Player::decodingLoop() {
    while (!isStopped) {
        if (isPaused) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }

        if (av_read_frame(formatCtx, packet) < 0) {
            // End of file or error
            isStopped = true;
            bufferCond.notify_all();
            break;
        }

        if (packet->stream_index == audioStreamIndex) {
            if (avcodec_send_packet(codecCtx, packet) < 0) {
                std::cerr << "Error sending packet to decoder." << std::endl;
                av_packet_unref(packet);
                continue;
            }

            while (avcodec_receive_frame(codecCtx, frame) == 0) {
                // Resample and convert the audio frame
                uint8_t* out_buffer = nullptr;
                int out_samples = swr_convert(swrCtx, &out_buffer, frame->nb_samples,
                    (const uint8_t**)frame->data, frame->nb_samples);
                if (out_samples < 0) {
                    std::cerr << "Error during resampling." << std::endl;
                    continue;
                }

                // Corrected function call: pass a pointer
                int out_channels = av_get_channel_layout_nb_channels(outChannelLayout);
                int buffer_size = av_samples_get_buffer_size(
                    nullptr, out_channels, out_samples, AV_SAMPLE_FMT_S16, 1);

                if (buffer_size < 0) {
                    std::cerr << "Error getting buffer size." << std::endl;
                    continue;
                }

                AudioBuffer audioBuffer;
                audioBuffer.data = (uint8_t*)av_malloc(buffer_size);
                memcpy(audioBuffer.data, out_buffer, buffer_size);
                audioBuffer.size = buffer_size;

                // Apply volume scaling
                int16_t* samples = (int16_t*)audioBuffer.data;
                int sampleCount = audioBuffer.size / sizeof(int16_t);
                double volumeFactor = static_cast<double>(volume) / SDL_MIX_MAXVOLUME;

                for (int i = 0; i < sampleCount; ++i) {
                    samples[i] = static_cast<int16_t>(samples[i] * volumeFactor);
                }

                {
                    std::lock_guard<std::mutex> lock(bufferMutex);
                    bufferQueue.push(audioBuffer);
                }
                bufferCond.notify_one();

                samplesPlayed += out_samples;
                av_free(out_buffer);
            }
        }

        av_packet_unref(packet);
    }
}

void Player::playbackLoop() {
    while (!isStopped) {
        AudioBuffer audioBuffer;
        {
            std::unique_lock<std::mutex> lock(bufferMutex);
            bufferCond.wait(lock, [this] { return !bufferQueue.empty() || isStopped; });

            if (isStopped && bufferQueue.empty()) {
                break;
            }

            if (!bufferQueue.empty()) {
                audioBuffer = bufferQueue.front();
                bufferQueue.pop();
            }
            else {
                continue;
            }
        }

        if (audioBuffer.size > 0) {
            SDL_QueueAudio(audioDevice, audioBuffer.data, audioBuffer.size);
            av_free(audioBuffer.data);
        }
    }
}

double Player::getDuration() {
    if (formatCtx && formatCtx->duration != AV_NOPTS_VALUE) {
        return formatCtx->duration / (double)AV_TIME_BASE;
    }
    return 0.0;
}

void Player::setVolume(int volume) {
    if (volume < 0) volume = 0;
    if (volume > SDL_MIX_MAXVOLUME) volume = SDL_MIX_MAXVOLUME;
    this->volume = volume;
}

void Player::seek(double position) {
    if (!formatCtx || audioStreamIndex < 0) return;

    int64_t target = static_cast<int64_t>(position * formatCtx->duration);
    if (av_seek_frame(formatCtx, audioStreamIndex, target, AVSEEK_FLAG_BACKWARD) < 0) {
        std::cerr << "Error seeking to position." << std::endl;
        return;
    }

    avcodec_flush_buffers(codecCtx);

    // Clear buffer queue
    {
        std::lock_guard<std::mutex> lock(bufferMutex);
        while (!bufferQueue.empty()) {
            AudioBuffer buf = bufferQueue.front();
            bufferQueue.pop();
            av_free(buf.data);
        }
    }

    samplesPlayed = static_cast<int64_t>((position * getDuration()) * codecCtx->sample_rate);
}


double Player::getPosition() {
    if (formatCtx && formatCtx->duration != AV_NOPTS_VALUE && codecCtx->sample_rate > 0) {
        double currentTime = (double)samplesPlayed / codecCtx->sample_rate;
        return currentTime / (getDuration() > 0 ? getDuration() : 1.0);
    }
    return 0.0;
}


void Player::pause() {
    if (isPlaying) {
        isPaused = !isPaused;
        if (isPaused) {
            SDL_PauseAudioDevice(audioDevice, 1);
        }
        else {
            SDL_PauseAudioDevice(audioDevice, 0);
        }
    }
}

void Player::stop() {
    if (isPlaying || isPaused) {
        isStopped = true;
        bufferCond.notify_all();
        if (decodeThread.joinable()) {
            decodeThread.join();
        }
        if (playbackThread.joinable()) {
            playbackThread.join();
        }
        if (audioDevice) {
            SDL_PauseAudioDevice(audioDevice, 1);
            SDL_CloseAudioDevice(audioDevice);
            audioDevice = 0;
        }
        cleanup();

        isPlaying = false;
        isPaused = false;
        isStopped = false;
    }
}

bool Player::initializeSDL() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_AudioSpec desiredSpec;
    SDL_zero(desiredSpec);
    desiredSpec.freq = 44100;                  // Sample rate
    desiredSpec.format = AUDIO_S16SYS;         // Audio format (16-bit signed)
    desiredSpec.channels = outChannelLayout.nb_channels; // Number of channels
    desiredSpec.samples = 4096;                // Buffer size
    desiredSpec.callback = nullptr;            // We're using SDL_QueueAudio

    audioDevice = SDL_OpenAudioDevice(nullptr, 0, &desiredSpec, &audioSpec, 0);
    if (audioDevice == 0) {
        std::cerr << "Failed to open SDL audio device: " << SDL_GetError() << std::endl;
        return false;
    }

    // Start playing audio
    SDL_PauseAudioDevice(audioDevice, 0);
    return true;
}


void Player::cleanup() {
    if (swrCtx) {
        swr_free(&swrCtx);
        swrCtx = nullptr;
    }
    if (frame) {
        av_frame_free(&frame);
        frame = nullptr;
    }
    if (packet) {
        av_packet_free(&packet);
        packet = nullptr;
    }
    if (codecCtx) {
        avcodec_free_context(&codecCtx);
        codecCtx = nullptr;
    }
    if (formatCtx) {
        avformat_close_input(&formatCtx);
        formatCtx = nullptr;
    }

    // Clear buffer queue
    while (!bufferQueue.empty()) {
        AudioBuffer buf = bufferQueue.front();
        bufferQueue.pop();
        av_free(buf.data);
    }

    // Uninitialize channel layouts
    av_channel_layout_uninit(&inChannelLayout);
    av_channel_layout_uninit(&outChannelLayout);
}


std::string Player::openFileDialog() {
    char filename[MAX_PATH] = "";

    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "Audio Files\0*.MP3;*.WAV;*.FLAC;*.AAC\0All Files\0*.*\0";
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    ofn.lpstrDefExt = "mp3";

    if (GetOpenFileName(&ofn)) {
        return std::string(filename);
    }
    else {
        return "";
    }
}
