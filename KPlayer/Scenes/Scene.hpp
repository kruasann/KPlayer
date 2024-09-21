#pragma once
#include <SDL.h>

class Scene {
public:
    virtual ~Scene() {}
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void handleEvent(SDL_Event* event) = 0;
    virtual void update() = 0;
};
