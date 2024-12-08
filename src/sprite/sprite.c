#include "sprite.h"

Sprite loadSprite(SDL_Renderer* renderer, const char* path) {
    Sprite s = {
        .x = 0,
        .y = 0,
        .texture = IMG_LoadTexture(renderer, path),
        .renderer = renderer
    };

    return s;
}