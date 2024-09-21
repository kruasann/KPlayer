#include "Button.hpp"
#include "TextRenderer.hpp"

Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height, const std::string& text, SDL_Color textColor, SDL_Color bgColor)
    : text(text), textColor(textColor), bgColor(bgColor) {
    buttonRect = { x, y, width, height };
    textTexture = TextRenderer::renderText(renderer, text, textColor);
}

Button::~Button() {
    if (textTexture) {
        SDL_DestroyTexture(textTexture);
    }
}

void Button::render(SDL_Renderer* renderer) {
    // Draw button background
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    SDL_RenderFillRect(renderer, &buttonRect);

    // Draw button text
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
    SDL_Rect textRect = {
        buttonRect.x + (buttonRect.w - textWidth) / 2,
        buttonRect.y + (buttonRect.h - textHeight) / 2,
        textWidth, textHeight
    };
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}

bool Button::isClicked(int mouseX, int mouseY) {
    return (mouseX >= buttonRect.x && mouseX <= buttonRect.x + buttonRect.w &&
        mouseY >= buttonRect.y && mouseY <= buttonRect.y + buttonRect.h);
}

void Button::setOnClick(std::function<void()> onClick) {
    onClickCallback = onClick;
}
