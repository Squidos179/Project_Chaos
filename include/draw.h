#ifndef PROJECT_CHAOS_DRAW_H
#define PROJECT_CHAOS_DRAW_H

void prepareScene(App &app);

void presentScene(App &app);

SDL_Texture *loadTexture(char *filename,App &app);

void blit(SDL_Texture *texture, int width, int height, App &app, Entity &player);

#endif //PROJECT_CHAOS_DRAW_H
