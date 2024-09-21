#include "TextRenderer.hpp"
#include <iostream>

// Initialize the static font member
TTF_Font* TextRenderer::font = nullptr;

bool TextRenderer::initialize(const std::string& fontFile, int fontSize) {
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr) {
        std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void TextRenderer::shutdown() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}

SDL_Texture* TextRenderer::renderText(SDL_Renderer* renderer, const std::string& message, SDL_Color color) {
    if (!font) {
        std::cerr << "Font not initialized." << std::endl;
        return nullptr;
    }

    SDL_Surface* surf = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!surf) {
        std::cerr << "Error rendering text: " << TTF_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);

    if (!texture) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}
