#ifndef LEVEL_H
#define LEVEL_H

#include "raylib.h"

typedef struct Platform {
    Vector2 start;
    Vector2 end;
} Platform;

void initPlatforms();

//void loadLevel(int currentLevel, Mario *mario, Platform *platforms, );

#endif
