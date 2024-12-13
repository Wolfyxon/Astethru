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
        .spawnTime = SDL_GetTicks()
    };

    return s;
}

SDL_Point Sprite_getTextureSize(Sprite* sprite) {
    SDL_Point size;
    SDL_QueryTexture(sprite->texture, NULL, NULL, &size.x, &size.y);
    
    return size;
}

void Sprite_draw(Sprite* sprite) {
    if(sprite->renderer == NULL || sprite->texture == NULL) {
        fprintf(stderr, "Invalid sprite \n");
        exit(1);
    }

    SDL_RenderCopy(sprite->renderer, sprite->texture, NULL, &sprite->rect);
}