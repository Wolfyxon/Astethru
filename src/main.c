#include <stdio.h>
#include <SDL2/SDL.h>

#define WINDOW_SIZE 800

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

    while (1) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) break;

        SDL_RenderClear(rend);
        SDL_RenderPresent(rend);
    }

    SDL_hid_exit();
    return 0;
}