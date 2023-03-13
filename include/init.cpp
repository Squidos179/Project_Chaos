#include "SDL.h"
#include "SDL_image.h"
#include "cstdio"
#include "defs.h"
#include "structs.h"


void initSDL(App &app)
{
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Ca marche pas la mon gars car : %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("Chaos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if(!app.window){
        printf("Impossible de creer %d x %d la fenetre : %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if(!app.renderer){
        printf("Impossible de faire le rendereur : %s\n", SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}