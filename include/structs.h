#ifndef PROJECT_CHAOS_STRUCTS_H
#define PROJECT_CHAOS_STRUCTS_H
#include "SDL.h"
#include "defs.h"

typedef struct Entity {
    SDL_Rect rect;
    SDL_Texture *texture;
    SDL_RendererFlip flip;
    float velocity;
    int dx;
    int dy;
    int health;
    int reaload;
    Entity *next;
};

typedef struct {
    Entity fighterHead, *fighterTail;
    Entity bulletHead, *bulletTail;
} Stage;

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int keyboard[MAX_KEYBOARD_KEYS];
    int fire;
} App;

#endif //PROJECT_CHAOS_STRUCTS_H
