#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "MainMenuScene.hpp"
#include "PlaybackScene.hpp"
#include "Scene.hpp"
#include "TextRenderer.hpp" // Include TextRenderer

int main(int argc, char* argv[]) {
    // Initialize SDL, TTF, and Mixer
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 || TTF_Init() == -1 || Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        std::cerr << "Failed to initialize SDL, TTF, or Mixer: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Initialize TextRenderer
    if (!TextRenderer::initialize("Assets/fonts/Arial.ttf", 24)) {
        std::cerr << "Failed to initialize TextRenderer." << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("KPlayer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Scene* currentScene = new MainMenuScene(renderer);

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            else {
                currentScene->handleEvent(&event);
            }
        }

        currentScene->update();

        // Check for scene switch
        if (MainMenuScene* menuScene = dynamic_cast<MainMenuScene*>(currentScene)) {
            if (menuScene->shouldSwitchToPlayback) {
                // Switch to PlaybackScene
                std::string filepath = menuScene->selectedFile;
                delete currentScene;
                currentScene = new PlaybackScene(renderer, filepath);
            }
        }
        else if (PlaybackScene* playbackScene = dynamic_cast<PlaybackScene*>(currentScene)) {
            if (playbackScene->shouldReturnToMenu) {
                delete currentScene;
                currentScene = new MainMenuScene(renderer);
            }
        }

        currentScene->render(renderer);
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    delete currentScene;
    TextRenderer::shutdown();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
