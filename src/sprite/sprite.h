#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    SDL_Rect rect;
    int spawnTime;
} Sprite;

Sprite Sprite_load(SDL_Renderer* renderer, const char* path);
void Sprite_draw(Sprite* sprite);

#endif