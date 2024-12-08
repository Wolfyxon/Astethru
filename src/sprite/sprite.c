#include "sprite.h"

Sprite Sprite_load(SDL_Renderer* renderer, const char* path) {
    SDL_Rect rect = {
        .w = 50,
        .h = 50,
        .x = 0,
        .y = 0,
    };
    
    Sprite s = {
        .texture = IMG_LoadTexture(renderer, path),
        .renderer = renderer,
        .rect = rect
    };

    return s;
}