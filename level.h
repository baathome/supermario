#ifndef LEVEL_H
#define LEVEL_H

#include "raylib.h"

#define MAX_PLATFORMS    20
#define PIXELS_BY_LINE   25.0
#define PIXELS_BY_COLUMN 10.0

void initPlatforms(Rectangle platforms[], int nPlatforms);

int getNextPlatformIndex(Rectangle platforms[], int nPlatforms);

//void loadLevel(int currentLevel, Mario *mario, Platform *platforms, );

#endif
