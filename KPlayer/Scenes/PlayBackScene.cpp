#include "PlaybackScene.hpp"
#include "TextRenderer.hpp"
#include <sstream>
#include <iomanip>

PlaybackScene::PlaybackScene(SDL_Renderer* renderer, const std::string& filepath)
    : renderer(renderer), filepath(filepath), isPlaying(false), volume(64), shouldReturnToMenu(false),
    playButton(renderer, 50, 500, 80, 40, "Play", { 255, 255, 255, 255 }, { 0, 128, 0, 255 }),
    pauseButton(renderer, 150, 500, 80, 40, "Pause", { 255, 255, 255, 255 }, { 128, 128, 0, 255 }),
    stopButton(renderer, 250, 500, 80, 40, "Stop", { 255, 255, 255, 255 }, { 128, 0, 0, 255 }),
    backButton(renderer, 700, 10, 80, 30, "Back", { 255, 255, 255, 255 }, { 100, 100, 100, 255 }),
    volumeSlider(renderer, 400, 510, 200, 20, 0, 128, volume, { 100, 100, 100, 255 }, { 0, 128, 255, 255 }),
    seekSlider(renderer, 50, 460, 700, 20, 0, 1000, 0, { 100, 100, 100, 255 }, { 255, 0, 0, 255 }),
    duration(0.0)
{
    // Start playing the file
    if (player.play(filepath)) {
        isPlaying = true;
        duration = player.getDuration();
    }
    else {
        shouldReturnToMenu = true;
    }
}

PlaybackScene::~PlaybackScene() {
    player.stop();
}

void PlaybackScene::render(SDL_Renderer* renderer) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    // Render playback controls
    playButton.render(renderer);
    pauseButton.render(renderer);
    stopButton.render(renderer);
    backButton.render(renderer);

    // Render volume slider
    volumeSlider.render(renderer);
    // Render seek slider
    seekSlider.render(renderer);

    // Display labels for sliders
    SDL_Color white = { 255, 255, 255, 255 };
    SDL_Texture* volumeLabel = TextRenderer::renderText(renderer, "Volume", white);
    SDL_Rect volumeLabelRect = { 400, 480, 100, 20 };
    SDL_RenderCopy(renderer, volumeLabel, nullptr, &volumeLabelRect);
    SDL_DestroyTexture(volumeLabel);

    // Display currently playing file
    SDL_Texture* nowPlayingTexture = TextRenderer::renderText(renderer, "Now Playing:", white);
    SDL_Rect nowPlayingRect = { 50, 50, 200, 30 };
    SDL_RenderCopy(renderer, nowPlayingTexture, nullptr, &nowPlayingRect);
    SDL_DestroyTexture(nowPlayingTexture);

    SDL_Texture* fileTexture = TextRenderer::renderText(renderer, filepath, white);
    SDL_Rect fileRect = { 50, 80, 700, 30 };
    SDL_RenderCopy(renderer, fileTexture, nullptr, &fileRect);
    SDL_DestroyTexture(fileTexture);

    // Display current time and total duration
    double currentTime = player.getPosition() * duration;
    int currentMinutes = static_cast<int>(currentTime) / 60;
    int currentSeconds = static_cast<int>(currentTime) % 60;

    int totalMinutes = static_cast<int>(duration) / 60;
    int totalSeconds = static_cast<int>(duration) % 60;

    std::ostringstream timeStream;
    timeStream << std::setw(2) << std::setfill('0') << currentMinutes << ":"
        << std::setw(2) << std::setfill('0') << currentSeconds << " / "
        << std::setw(2) << std::setfill('0') << totalMinutes << ":"
        << std::setw(2) << std::setfill('0') << totalSeconds;

    SDL_Texture* timeTexture = TextRenderer::renderText(renderer, timeStream.str(), white);
    SDL_Rect timeRect = { 350, 430, 100, 20 };
    SDL_RenderCopy(renderer, timeTexture, nullptr, &timeRect);
    SDL_DestroyTexture(timeTexture);
}

void PlaybackScene::handleEvent(SDL_Event* event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX = event->button.x;
        int mouseY = event->button.y;

        if (playButton.isClicked(mouseX, mouseY)) {
            // Start playback
            if (!isPlaying) {
                if (player.play(filepath)) {
                    isPlaying = true;
                    isPaused = false;
                    duration = player.getDuration();
                }
            }
            else {
                // If already playing, restart playback
                player.stop();
                if (player.play(filepath)) {
                    isPlaying = true;
                    isPaused = false;
                    duration = player.getDuration();
                }
            }
        }
        else if (pauseButton.isClicked(mouseX, mouseY)) {
            // Pause or resume
            if (isPlaying) {
                player.pause();
                isPaused = !isPaused;
            }
        }
        else if (stopButton.isClicked(mouseX, mouseY)) {
            // Stop playback
            if (isPlaying || isPaused) {
                player.stop();
                isPlaying = false;
                isPaused = false;
            }
        }
        else if (backButton.isClicked(mouseX, mouseY)) {
            shouldReturnToMenu = true;
        }
    }

    // Handle volume slider (handle it during mouse motion to allow dragging)
    if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN) {
        if (volumeSlider.handleEvent(event)) {
            volume = volumeSlider.getValue();
            player.setVolume(volume);
        }

        // Handle seek slider (handle it during mouse motion to allow dragging)
        if (seekSlider.handleEvent(event)) {
            double seekPosition = static_cast<double>(seekSlider.getValue()) / 1000.0;
            player.seek(seekPosition);
        }
    }
}


void PlaybackScene::update() {
    // Update seek slider based on current playback position
    if (isPlaying && duration > 0) {
        double position = player.getPosition(); // 0.0 to 1.0
        int sliderValue = static_cast<int>(position * 1000);
        seekSlider.setValue(sliderValue);
    }
}
