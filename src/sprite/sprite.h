#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

typedef struct {
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    SDL_FRect rect;
    int spawnTime;
} Sprite;

Sprite Sprite_load(SDL_Renderer* renderer, const char* path);

SDL_Point Sprite_getTextureSize(Sprite* sprite);
bool Sprite_touches(Sprite* sprite, Sprite* other);
void Sprite_draw(Sprite* sprite);

#endif