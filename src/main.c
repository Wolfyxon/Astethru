#include <stdio.h>
#include <SDL2/SDL.h>

int main(void) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Astethru", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
    SDL_Event event;

    while (1) {    
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) break;
    }

    return 0;
}