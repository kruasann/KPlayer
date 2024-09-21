#include "Slider.hpp"

Slider::Slider(SDL_Renderer* renderer, int x, int y, int width, int height, int minValue, int maxValue, int initialValue, SDL_Color bgColor, SDL_Color fillColor)
    : minValue(minValue), maxValue(maxValue), currentValue(initialValue), bgColor(bgColor), fillColor(fillColor), isDragging(false) {
    backgroundRect = { x, y, width, height };
    fillRect = { x, y, (int)((initialValue - minValue) / (float)(maxValue - minValue) * width), height };
}

Slider::~Slider() {}

void Slider::render(SDL_Renderer* renderer) {
    // Draw background
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    SDL_RenderFillRect(renderer, &backgroundRect);

    // Draw fill
    SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
    SDL_RenderFillRect(renderer, &fillRect);
}

bool Slider::handleEvent(SDL_Event* event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX = event->button.x;
        int mouseY = event->button.y;

        SDL_Point mousePoint = { mouseX, mouseY };
        if (SDL_PointInRect(&mousePoint, &backgroundRect)) {

            isDragging = true;
            mouseXOffset = mouseX - backgroundRect.x;
            // Update fillRect width based on mouse position
            fillRect.w = mouseXOffset;
            // Update currentValue
            currentValue = minValue + (fillRect.w * (maxValue - minValue)) / backgroundRect.w;
            return true;
        }
    }
    else if (event->type == SDL_MOUSEBUTTONUP) {
        if (event->button.button == SDL_BUTTON_LEFT) {
            isDragging = false;
        }
    }

    else if (event->type == SDL_MOUSEMOTION) {
        if (isDragging && (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT))) {
            int mouseX = event->motion.x;
            // Clamp mouseX to slider boundaries
            mouseX = std::max(backgroundRect.x, std::min(mouseX, backgroundRect.x + backgroundRect.w));
            mouseXOffset = mouseX - backgroundRect.x;
            // Update fillRect width
            fillRect.w = mouseXOffset;
            // Update currentValue
            currentValue = minValue + (fillRect.w * (maxValue - minValue)) / backgroundRect.w;
            return true;
        }
    }
    return false;
}

int Slider::getValue() const {
    return currentValue;
}

void Slider::setValue(int value) {
    currentValue = value;
    fillRect.w = (value - minValue) * backgroundRect.w / (maxValue - minValue);
}

