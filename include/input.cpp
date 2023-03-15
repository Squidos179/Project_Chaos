#include "SDL.h"
#include "structs.h"
#include "cstdio"
#include "structs.h"

void doKeyDown(SDL_KeyboardEvent *event, App &app)
{
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
    {
        app.keyboard[event->keysym.scancode] = 1;
    }
}

void doKeyUp(SDL_KeyboardEvent *event, App &app)
{
    if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
    {
        app.keyboard[event->keysym.scancode] = 0;
    }
}

void doInput(Entity player, App &app){

    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch (event.type) {

            case SDL_QUIT:
                exit(1);
                break;

            case SDL_KEYDOWN:
                doKeyDown(&event.key, app);
                break;

            case SDL_KEYUP:
                doKeyUp(&event.key, app);

            default:
                break;
        }
    }
}
