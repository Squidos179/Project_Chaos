#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include <cstring>
#include "include/structs.h"
#include "include/init.h"
#include "include/input.h"
#include "include/draw.h"
#include "SDL_mixer.h"
#include "include/stage.h"
#include "stdio.h"

App app;
Entity player;
Entity oussama;
Entity bullet;
Stage stage;

int main(int argc, char *argv[]) {

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));
    memset(&bullet, 0, sizeof(Entity));
    memset(&oussama, 0, sizeof(Entity));
    memset(&stage, 0, sizeof(Stage));

    initSDL(app);

    stageinit(player, oussama, bullet, app, stage);

    Mix_Music * sound = Mix_LoadMUS("pipe.mp3");

    SDL_Surface * surface = SDL_LoadBMP("pipe.bmp");

    SDL_SetWindowIcon(app.window, surface);

    while(1){

        prepareScene(app);

        doInput(player, app);

        logic(player, bullet, app);

        if (player.rect.y > 740)
        {
            player.rect.y = -20;
        }

        if (player.rect.y < -20)
        {
            player.rect.y = 740;
        }

        if (player.rect.x > 1300)
        {
            player.rect.x = -20;
        }

        if (player.rect.x < -20)
        {
            player.rect.x = 1300;
        }

        fireBullet(bullet, player, app);

        if (SDL_HasIntersection(&player.rect, &oussama.rect))
        {
            player.velocity = 0;
        }

        if (SDL_HasIntersection(&bullet.rect, &oussama.rect))
        {
            Mix_PlayMusic(sound, 0);
            bullet.health = 0;
        }

        draw(player, app, oussama);

        presentScene(app);

        SDL_Delay(16);
    }

    return 0;
}
