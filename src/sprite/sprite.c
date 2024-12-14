#include "sprite.h"

Sprite Sprite_load(SDL_Renderer* renderer, const char* path) {
    SDL_FRect rect = {
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

bool Sprite_touches(Sprite* sprite, Sprite* other) {
    SDL_FRect a = sprite->rect;
    SDL_FRect b = other->rect;
    
    float l1 = a.x;
    float r1 = a.x + a.w;
    float t1 = a.y;
    float b1 = a.y + a.h;
    
    float l2 = b.x;
    float r2 = b.x + b.w;
    float t2 = b.y;
    float b2 = b.y + b.h;
    
    return !(l1 > r2 || r1 < l2 || t1 > b2 || b1 < t2);
}

void Sprite_draw(Sprite* sprite) {
    if(sprite->renderer == NULL || sprite->texture == NULL) {
        fprintf(stderr, "Invalid sprite \n");
        exit(1);
    }

    SDL_RenderCopyF(sprite->renderer, sprite->texture, NULL, &sprite->rect);
}