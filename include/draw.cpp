#include "SDL.h"
#include "SDL_image.h"
#include "cstdio"
#include "structs.h"
#include "string"

void prepareScene(App &app){
    SDL_SetRenderDrawColor(app.renderer, 255, 127, 127, 255);
    SDL_RenderClear(app.renderer);

    if (app.renderer == NULL)
    {
        printf(SDL_GetError());
    }

}

void presentScene(App &app){
    SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadTexture(char *filename, App &app){
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(app.renderer, filename);

    return texture;
}

void blit(SDL_Texture *texture, int width, int height, App &app, Entity &entity)
{
    SDL_RenderCopyEx(app.renderer, texture, NULL, &entity.rect, 0, NULL, entity.flip);
}