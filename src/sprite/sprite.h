#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
    float x;
    float y;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
} Sprite;

Sprite Sprite_load(SDL_Renderer* renderer, const char* path);