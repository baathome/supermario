#include "level.h"
#include <stdio.h>

void initPlatforms(Rectangle platforms[], int nPlatforms) {
    for (int i = 0; i < nPlatforms; i++) {
        platforms[i].height = -1.0;
    }
}

void initGameObjects(GameObject objects[], int nGameObjects) {
    for (int i = 0; i < nGameObjects; i++) {
        objects[i].type = -1;
    }
}

int getNextPlatformIndex(Rectangle platforms[], int nPlatforms) {
    int i = 0;

    while (i < nPlatforms) {
        if (platforms[i].height == -1.0) return i;

        //printf("\ni %d - %f\n", i, platforms[i].height);
        //getchar();
        i++;
    }
    return i;
}

int getNextGameObjectIndex(GameObject objects[], int nGameObjects) {
    int i = 0;

    while (i < nGameObjects) {
        if (objects[i].type == -1.0) return i;

        i++;
    }
    return i;
}

int collisionCheckMario(Mario mario, Rectangle platforms[], int nPlatforms) {
    int i = 0, n = getNextPlatformIndex(platforms, nPlatforms);

    for (int i = 0; i < n; i++) {
        if (CheckCollisionRecs(platforms[i], (Rectangle) { mario.pos.x, mario.pos.y, MARIO_WIDTH, MARIO_HEIGHT })) {
            if (platforms[i].y > mario.pos.y) return -1;  // mario acertou por baixo

            return 1;                                     //mario acertou por cima
        }
    }

    return 0;
}
