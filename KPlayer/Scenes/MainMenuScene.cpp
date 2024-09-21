#include "MainMenuScene.hpp"
#include "Player.hpp"

MainMenuScene::MainMenuScene(SDL_Renderer* renderer)
    : renderer(renderer), isMenuOpen(false), shouldSwitchToPlayback(false) {
    // Initialize playback history (could be loaded from a file)
}

MainMenuScene::~MainMenuScene() {}

void MainMenuScene::render(SDL_Renderer* renderer) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    // Render menu bar
    renderMenuBar();

    SDL_Color white = { 255, 255, 255, 255 };

    // Render header
    SDL_Texture* textTexture = TextRenderer::renderText(renderer, "Playback History", white);
    SDL_Rect textRect = { 50, 50, 200, 30 };
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    SDL_DestroyTexture(textTexture);

    // Render playback history
    int yOffset = 100;
    for (size_t i = 0; i < playbackHistory.size(); i++) {
        const FileInfo& file = playbackHistory[i];

        // Render text for each file
        SDL_Texture* nameTexture = TextRenderer::renderText(renderer, file.name, white);
        SDL_Rect nameRect = { 50, yOffset, 700, 30 };
        SDL_RenderCopy(renderer, nameTexture, nullptr, &nameRect);
        SDL_DestroyTexture(nameTexture);

        yOffset += 40;
    }
}

void MainMenuScene::handleEvent(SDL_Event* event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX = event->button.x;
        int mouseY = event->button.y;

        // Create a SDL_Point variable
        SDL_Point mousePoint = { mouseX, mouseY };

        // Check if click is on menu bar
        if (mouseY >= 0 && mouseY <= 30) {
            // Check if "File" menu item is clicked
            if (mouseX >= 10 && mouseX <= 60) {
                isMenuOpen = !isMenuOpen;
            }
        }
        else if (isMenuOpen && SDL_PointInRect(&mousePoint, &menuRect), &menuRect) {
            // Check if "Open File" is clicked
            if (mouseY >= 35 && mouseY <= 55) {
                // Open file dialog
                std::string filepath = Player::openFileDialog();
                if (!filepath.empty()) {
                    // Add to playback history
                    FileInfo file;
                    file.name = filepath;
                    file.isPlaying = false;
                    playbackHistory.push_back(file);

                    // Set to switch to playback scene
                    selectedFile = filepath;
                    shouldSwitchToPlayback = true;
                }
            }
            // Check if "Exit" is clicked
            else if (mouseY >= 60 && mouseY <= 80) {
                // Exit application
                SDL_Event quitEvent;
                quitEvent.type = SDL_QUIT;
                SDL_PushEvent(&quitEvent);
            }
            isMenuOpen = false;
        }
        else {
            isMenuOpen = false;

            // Check if a file in the playback history was clicked
            int yOffset = 100;
            for (size_t i = 0; i < playbackHistory.size(); i++) {
                SDL_Rect fileRect = { 50, yOffset, 700, 30 };
                if (mouseX >= fileRect.x && mouseX <= fileRect.x + fileRect.w &&
                    mouseY >= fileRect.y && mouseY <= fileRect.y + fileRect.h) {
                    // User clicked on a file
                    selectedFile = playbackHistory[i].name;
                    shouldSwitchToPlayback = true;
                    break;
                }
                yOffset += 40;
            }
        }
    }
}

void MainMenuScene::update() {
    // Update logic if needed
}

void MainMenuScene::renderMenuBar() {
    // Draw menu bar background
    SDL_Rect menuBarRect = { 0, 0, 800, 30 };
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderFillRect(renderer, &menuBarRect);

    SDL_Color white = { 255, 255, 255, 255 };

    // Render "File" menu item
    SDL_Texture* fileMenuTexture = TextRenderer::renderText(renderer, "File", white);
    SDL_Rect fileMenuRect = { 10, 5, 50, 20 };
    SDL_RenderCopy(renderer, fileMenuTexture, nullptr, &fileMenuRect);
    SDL_DestroyTexture(fileMenuTexture);

    // If menu is open, render menu items
    if (isMenuOpen) {
        // Draw menu background
        menuRect = { 10, 30, 100, 60 };
        SDL_SetRenderDrawColor(renderer, 70, 70, 70, 255);
        SDL_RenderFillRect(renderer, &menuRect);

        // Render "Open File" menu item
        SDL_Texture* openFileTexture = TextRenderer::renderText(renderer, "Open File", white);
        SDL_Rect openFileRect = { 15, 35, 80, 20 };
        SDL_RenderCopy(renderer, openFileTexture, nullptr, &openFileRect);
        SDL_DestroyTexture(openFileTexture);

        // Render "Exit" menu item
        SDL_Texture* exitTexture = TextRenderer::renderText(renderer, "Exit", white);
        SDL_Rect exitRect = { 15, 60, 80, 20 };
        SDL_RenderCopy(renderer, exitTexture, nullptr, &exitRect);
        SDL_DestroyTexture(exitTexture);
    }
}