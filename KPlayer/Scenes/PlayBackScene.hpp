#pragma once
#include <SDL.h>
#include <string>
#include "Button.hpp"
#include "Player.hpp"
#include "Scene.hpp"
#include "Slider.hpp"

class PlaybackScene : public Scene {
public:
    PlaybackScene(SDL_Renderer* renderer, const std::string& filepath);
    ~PlaybackScene();

    void render(SDL_Renderer* renderer) override;
    void handleEvent(SDL_Event* event) override;
    void update() override;

    bool shouldReturnToMenu;

private:
    SDL_Renderer* renderer;
    std::string filepath;
    Button playButton;
    Button pauseButton;
    Button stopButton;
    Button backButton;
    Player player;
    int volume;
    bool isPlaying;
    bool isPaused;

    Slider volumeSlider;
    Slider seekSlider;

    double duration; // Total duration in seconds
};
