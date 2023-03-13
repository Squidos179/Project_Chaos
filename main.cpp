#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include <cstring>
#include "include/structs.h"
#include "include/init.h"
#include "include/input.h"
#include "include/draw.h"

App app;
Entity player;
Entity oussama;

int main(int argc, char *argv[]) {

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    initSDL(app);

    player.texture = loadTexture("simon.jpg", app);

    oussama.texture = loadTexture("oussama.jpg", app);

    player.velocity = 4;
    player.rect.x = 100;
    player.rect.y = 100;
    player.rect.h = 32;
    player.rect.w = 32;

    oussama.rect.x = 600;
    oussama.rect.y = 360;
    oussama.rect.h = 128;
    oussama.rect.w = 128;

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

        std::cout << "x :" << player.rect.x << " y :" << player.rect.y << std::endl;

        blit(player.texture, 32, 32, app, player);
        blit(oussama.texture, 128, 128, app, oussama);

        presentScene(app);

        SDL_Delay(16);
    }

    return 0;
}
