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
    int fire;
} App;

typedef struct {
    SDL_Rect rect;
    SDL_Texture *texture;
    SDL_RendererFlip flip;
    float velocity;
    int dx;
    int dy;
    int health;
} Entity;

#endif //PROJECT_CHAOS_STRUCTS_H
