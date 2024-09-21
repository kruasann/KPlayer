#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TextRenderer {
public:
    static bool initialize(const std::string& fontFile, int fontSize);
    static void shutdown();
    static SDL_Texture* renderText(SDL_Renderer* renderer, const std::string& message, SDL_Color color);

private:
    static TTF_Font* font;
};
