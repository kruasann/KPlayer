#pragma once
#include <SDL.h>
#include <string>

class Slider {
public:
    Slider(SDL_Renderer* renderer, int x, int y, int width, int height, int minValue, int maxValue, int initialValue, SDL_Color bgColor, SDL_Color fillColor);
    ~Slider();

    void render(SDL_Renderer* renderer);
    bool handleEvent(SDL_Event* event);
    int getValue() const;
    void setValue(int value);

private:
    SDL_Rect backgroundRect;
    SDL_Rect fillRect;
    int minValue;
    int maxValue;
    int currentValue;
    SDL_Color bgColor;
    SDL_Color fillColor;
    bool isDragging;
    int mouseXOffset;
};
