// Player.hpp

#pragma once
#include <SDL.h>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <queue>

// FFmpeg headers
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
#include <libavutil/avutil.h>
#include <libswscale/swscale.h>
}

class Player {
public:
    Player();
    ~Player();

    bool play(const std::string& filepath);
    void pause();
    void stop();
    void setVolume(int volume); // 0 to SDL_MIX_MAXVOLUME (128)
    void seek(double position); // 0.0 to 1.0

    double getPosition();       // 0.0 to 1.0
    double getDuration();       // Duration in seconds

    static std::string openFileDialog();

private:
    AVFormatContext* formatCtx;
    AVCodecContext* codecCtx;
    const AVCodec* codec;
    AVPacket* packet;
    AVFrame* frame;
    SwrContext* swrCtx;
    int audioStreamIndex;

    SDL_AudioDeviceID audioDevice;
    SDL_AudioSpec audioSpec;

    // Buffer management
    struct AudioBuffer {
        uint8_t* data;
        int size;
    };
    std::queue<AudioBuffer> bufferQueue;

    std::atomic<bool> isPlaying;
    std::atomic<bool> isPaused;
    std::atomic<bool> isStopped;
    std::atomic<int> volume;

    std::thread decodeThread;
    std::thread playbackThread;
    std::mutex bufferMutex;
    std::condition_variable bufferCond;

    std::atomic<int64_t> samplesPlayed;

    uint64_t inChannelLayout;
    uint64_t outChannelLayout;

    void decodingLoop();
    void playbackLoop();
    bool initializeSDL();
    void cleanup();
};
