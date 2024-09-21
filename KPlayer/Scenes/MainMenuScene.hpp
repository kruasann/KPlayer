#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include "Button.hpp"
#include "TextRenderer.hpp"
#include "Scene.hpp" // Include the base class header

// Structure for storing file information
struct FileInfo {
    std::string name;
    bool isPlaying; // Indicates if the file is currently playing
};

class MainMenuScene : public Scene { // Inherit from Scene
public:
    MainMenuScene(SDL_Renderer* renderer);
    ~MainMenuScene();

    void render(SDL_Renderer* renderer) override; // Implement virtual functions
    void handleEvent(SDL_Event* event) override;
    void update() override;

    bool shouldSwitchToPlayback;
    std::string selectedFile;

private:
    SDL_Renderer* renderer;
    std::vector<FileInfo> playbackHistory; // Playback history
    void renderMenuBar();                  // Render the menu bar
    bool isMenuOpen;
    SDL_Rect menuRect;
};
