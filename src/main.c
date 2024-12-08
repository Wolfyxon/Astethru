#include <stdio.h>
#include <SDL2/SDL.h>
#include "sprite/sprite.h"
#include "spriteArray/spriteArray.h"

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

    SpriteArray* projectiles = SpriteArray_new(MAX_PROJECTILES);
    SpriteArray* asteroids = SpriteArray_new(MAX_ASTEROIDS);

    Sprite player = Sprite_load(rend, "assets/img/ship.png");
    player.rect.w = 80;
    player.rect.h = 80;
    player.rect.x = WINDOW_SIZE / 2 - player.rect.w / 2;
    player.rect.y = WINDOW_SIZE - player.rect.h - 50;

    float playerX = player.rect.x;
    float lastTime = SDL_GetTicks();
    float lastFireTime = 0;

    while (1) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT) break;

        float now = SDL_GetTicks();
        float delta = (now - lastTime);
        lastTime = now;

        int mx, my;
        Uint32 mouse = SDL_GetMouseState(&mx, &my);

        if(mouse & SDL_BUTTON_LEFT) {
            if(now > lastFireTime + 500) {
                lastFireTime = now;
                
                Sprite proj = Sprite_load(rend, "assets/img/laser.png");
                proj.rect.x = player.rect.x;
                proj.rect.y = player.rect.y;

                SpriteArray_push(projectiles, proj);
            }
        }

        playerX = lerp(playerX, mx - player.rect.w / 2, 0.01 * delta);
        player.rect.x = playerX;

        SDL_RenderClear(rend);

        for(int i = 0; i < projectiles->length; i++) {
            Sprite* proj = &projectiles->data[i];
            proj->rect.y -= 2 * delta;
            Sprite_draw(proj);
        }

        Sprite_draw(&player);
        SDL_RenderPresent(rend);
    }

    SDL_hid_exit();
    return 0;
}