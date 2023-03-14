#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include <cstring>
#include "include/structs.h"
#include "include/init.h"
#include "include/input.h"
#include "include/draw.h"
#include "SDL_mixer.h"

App app;
Entity player;
Entity oussama;
Entity bullet;

int main(int argc, char *argv[]) {

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));
    memset(&bullet, 0, sizeof(Entity));
    memset(&oussama, 0, sizeof(Entity));

    initSDL(app);

    player.texture = loadTexture("simon.jpg", app);

    oussama.texture = loadTexture("oussama.jpg", app);

    bullet.texture = loadTexture("bictor.jpg", app);

    player.velocity = 4;
    player.rect.x = 100;
    player.rect.y = 100;
    player.rect.h = 32;
    player.rect.w = 32;

    oussama.rect.x = 600;
    oussama.rect.y = 360;
    oussama.rect.h = 128;
    oussama.rect.w = 128;

    bullet.rect.x = 30;
    bullet.rect.y = 30;
    bullet.rect.h = 16;
    bullet.rect.w = 16;

    Mix_Music * sound = Mix_LoadMUS("fart.wav");

    while(1){

        prepareScene(app);

        doInput(player, app);

        player.rect.y += 0;

        if (app.up)
        {
            player.rect.y -= player.velocity;
        }

        if (app.down)
        {
            player.rect.y += player.velocity;
        }

        if (app.left)
        {
            player.rect.x -= player.velocity;
            player.flip = SDL_FLIP_HORIZONTAL;
        }

        if (app.right)
        {
            player.rect.x += player.velocity;
            player.flip = SDL_FLIP_NONE;
        }

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

        if (SDL_HasIntersection(&player.rect, &oussama.rect))
        {
            player.velocity = 0;
        }

        if (app.fire && bullet.health == 0)
        {
            bullet.rect.x = player.rect.x;
            bullet.rect.y = player.rect.y;
            bullet.dx = 16;
            bullet.dy = 0;
            bullet.health = 1;
        }

        bullet.rect.x += bullet.dx;

        if (bullet.health == 1)
        {
            blit(bullet.texture, app, bullet);
        }

        if (bullet.rect.x > SCREEN_WIDTH)
        {
            bullet.health = 0;
        }

        if (SDL_HasIntersection(&bullet.rect, &oussama.rect))
        {
            Mix_PlayMusic(sound, 0);
            bullet.health = 0;
            printf("Success");
        }

        std::cout << app.fire << std::endl;

        blit(player.texture, app, player);
        blit(oussama.texture, app, oussama);

        presentScene(app);

        SDL_Delay(16);
    }

    return 0;
}
