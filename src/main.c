#include <stdio.h>
#include <SDL2/SDL.h>
#include "sprite/sprite.h"

#define WINDOW_SIZE 800

float lerp(float start, float end, float speed) {
    return (1.0 - speed) * start + speed * end;
}

int main(void) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow(
        "Astethru", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        WINDOW_SIZE, WINDOW_SIZE, 
        0
    );
    
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;

    Sprite player = Sprite_load(rend, "assets/img/ship.png");
    player.rect.x = WINDOW_SIZE / 2 - player.rect.w / 2;
    player.rect.y = WINDOW_SIZE - player.rect.h - 50;

    while (1) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) break;

        SDL_RenderClear(rend);

        Sprite_draw(&player);
        SDL_RenderPresent(rend);
    }

    SDL_hid_exit();
    return 0;
}