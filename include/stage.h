#include "structs.h"

#ifndef PROJECT_CHAOS_STAGE_H
#define PROJECT_CHAOS_STAGE_H

void stageinit(Entity &player, Entity &oussama, Entity &bullet, App &app, Stage &stage);
static void initPlayer(Entity &player, App &app, Stage &stage);
void logic(Entity &player, Entity &bullet, App &app);
void draw(Entity &player, App &app, Entity &oussama);
void fireBullet(Entity &bullet, Entity &player, App &app);

#endif //PROJECT_CHAOS_STAGE_H
