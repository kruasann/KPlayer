#pragma once
#include <SDL.h>
#include <string>
#include <functional>

class Button {
public:
    Button(SDL_Renderer* renderer, int x, int y, int width, int height, const std::string& text, SDL_Color textColor, SDL_Color bgColor);
    ~Button();

    void render(SDL_Renderer* renderer);
    bool isClicked(int mouseX, int mouseY);
    void setOnClick(std::function<void()> onClick);

private:
    SDL_Rect buttonRect;
    SDL_Color textColor;
    SDL_Color bgColor;
    std::string text;
    SDL_Texture* textTexture;
    std::function<void()> onClickCallback;
};
