#include "stage.h"
#include "structs.h"
#include "SDL.h"
#include "draw.h"

void stageinit(Entity &player, Entity &oussama, Entity &bullet, App &app, Stage &stage)
{
    memset(&stage, 0, sizeof(Stage));
    stage.fighterTail = &stage.fighterHead;
    stage.bulletTail = &stage.bulletHead;

    initPlayer(player, app, stage);

    oussama.rect.x = 600;
    oussama.rect.y = 360;
    oussama.rect.h = 128;
    oussama.rect.w = 128;
    oussama.collision.left.x = oussama.rect.x;
    oussama.collision.left.y = oussama.rect.y;
    oussama.collision.left.h = 128;
    oussama.collision.left.w = 3;

    bullet.rect.x = 30;
    bullet.rect.y = 30;
    bullet.rect.h = 16;
    bullet.rect.w = 16;

    bullet.texture = loadTexture("bictor.jpg", app);
    oussama.texture = loadTexture("oussama.jpg", app);
    player.collision.texture = loadTexture("collision.png", app);
    oussama.collision.texture = loadTexture("collisionL.png", app);
}

static void initPlayer(Entity &player, App &app, Stage &stage)
{
    memset(&player, 0, sizeof(Entity));
    player.texture = loadTexture("simon.jpg", app);

    stage.fighterTail->next = &player;
    stage.fighterTail = &player;

    player.rect.x = 100;
    player.rect.y = 100;
    player.rect.h = 32;
    player.rect.w = 32;
    player.collision.right.x = player.rect.x + 29;
    player.collision.right.y = player.rect.y;
    player.collision.right.h = 32;
    player.collision.right.w = 3;
}

void logic(Entity &player, Entity &bullet, App &app)
{

    if (player.reaload > 0)
    {
        player.reaload--;
    }

    if (app.keyboard[SDL_SCANCODE_UP])
    {
        player.rect.y -= PLAYER_SPEED;
    }

    if (app.keyboard[SDL_SCANCODE_DOWN])
    {
        player.rect.y += PLAYER_SPEED;
    }

    if (app.keyboard[SDL_SCANCODE_LEFT])
    {
        player.rect.x -= PLAYER_SPEED;
        player.flip = SDL_FLIP_HORIZONTAL;
    }

    if (app.keyboard[SDL_SCANCODE_RIGHT])
    {
        player.rect.x += PLAYER_SPEED;
        player.flip = SDL_FLIP_NONE;
    }

    if (app.keyboard[SDL_SCANCODE_LCTRL])
    {
        app.fire = 1;
    }
}

void fireBullet(Entity &bullet, Entity &player, App &app)
{
    if (app.keyboard[SDL_SCANCODE_LCTRL] && bullet.health == 0)
    {
        bullet.rect.x = player.rect.x + 8;
        bullet.rect.y = player.rect.y + 8;
        if (player.flip == SDL_FLIP_HORIZONTAL)
        {
            bullet.dx = -16;
        }else {
            bullet.dx = 16;
        }
        bullet.health = 1;
    }

    bullet.rect.x += bullet.dx;

    if (bullet.health > 0)
    {
        blit(bullet.texture, app, bullet);
    }

    if (bullet.rect.x > SCREEN_WIDTH)
    {
        bullet.health = 0;
    }
    if (bullet.rect.x < 0)
    {
        bullet.health = 0;
    }
}

void draw(Entity &player, App &app, Entity &oussama)
{
    player.collision.right.x = player.rect.x + 29;
    player.collision.right.y = player.rect.y;
    blit(player.texture, app, player);
    blit(oussama.texture, app, oussama);
    SDL_RenderCopyEx(app.renderer, oussama.collision.texture, NULL, &oussama.collision.left, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(app.renderer, player.collision.texture, NULL, &player.collision.right, 0, NULL, SDL_FLIP_NONE);
}