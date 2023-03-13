#ifndef PROJECT_CHAOS_STRUCTS_H
#define PROJECT_CHAOS_STRUCTS_H
#include "SDL.h"
#include "defs.h"

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;
    int down;
    int left;
    int right;
} App;

typedef struct {
    SDL_Rect rect;
    SDL_Texture *texture;
    SDL_RendererFlip flip;
    float velocity;
} Entity;

#endif //PROJECT_CHAOS_STRUCTS_H
