#include "sprite.h"

Sprite Sprite_load(SDL_Renderer* renderer, const char* path) {
    SDL_Rect rect = {
        .w = 50,
        .h = 50,
        .x = 0,
        .y = 0,
    };
    
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);

    if(texture == NULL) {
        fprintf(stderr, "Failed to load texture %s", path);
    }

    Sprite s = {
        .texture = texture,
        .renderer = renderer,
        .rect = rect,
        .renderCycles = 0
    };

    return s;
}

void Sprite_draw(Sprite* sprite) {
    SDL_RenderCopy(sprite->renderer, sprite->texture, NULL, &sprite->rect);
    sprite->renderCycles++;
}