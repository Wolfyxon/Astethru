#include <stdio.h>
#include <SDL2/SDL.h>
#include "sprite/sprite.h"

#define WINDOW_SIZE 800
#define MAX_PROJECTILES 256
#define MAX_ASTEROIDS 128

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

    Sprite* projectiles[MAX_PROJECTILES];
    Sprite* asteroids[MAX_ASTEROIDS];

    Sprite player = Sprite_load(rend, "assets/img/ship.png");
    player.rect.w = 80;
    player.rect.h = 80;
    player.rect.x = WINDOW_SIZE / 2 - player.rect.w / 2;
    player.rect.y = WINDOW_SIZE - player.rect.h - 50;

    while (1) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) break;

        int mx, my;
        SDL_GetMouseState(&mx, &my);

        player.rect.x = mx - player.rect.w / 2;

        SDL_RenderClear(rend);

        Sprite_draw(&player);
        SDL_RenderPresent(rend);
    }

    SDL_hid_exit();
    return 0;
}