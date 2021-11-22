#include "level.h"
#include <stdio.h>
#include <math.h>

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

// void unloadGameobjectsTX(GameObject objects[], int nGameObjects) {
//     for (int i = 0; i < nGameObjects; i++) {
//         UnloadTexture(objects[i].tx);
//     }
// }

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

Rectangle *collisionCheck(Rectangle *rect, Rectangle platforms[], int nPlatforms) {
    int i = 0, n = getNextPlatformIndex(platforms, nPlatforms);

    for (int i = 0; i < n; i++) {
        if (CheckCollisionRecs(platforms[i], *rect)) {
            return platforms + i;
        }
    }

    return NULL;
}

void hitPlatform(ColRectangle *col_rect, Rectangle *platform) {
    float plat_right = platform->x + platform->width;
    float plat_bottom = platform->y + platform->height;

    float col_right = col_rect->rect.x + col_rect->rect.width;
    float col_bottom = col_rect->rect.y + col_rect->rect.height;


    if (col_rect->rect.x < platform->x && col_right > platform->x) {
        if (fabsf(col_rect->rect.y - plat_bottom) < STEP_HEIGHT) {
            if (col_rect->speed.y < 0.0) {
                col_rect->speed.y = 0.0;
            }

            col_rect->rect.y = plat_bottom;
        } else if (fabsf(col_bottom - platform->y) < STEP_HEIGHT) {
            if (col_rect->speed.y > 0.0) {
                col_rect->speed.y = 0.0;
            }

            col_rect->rect.y = platform->y - MARIO_HEIGHT;
        } else {
            col_rect->speed.x = 0.0;
            col_rect->rect.x = platform->x - col_rect->rect.width;
        }
    } else if (col_rect->rect.x < plat_right && col_right > plat_right) {
        if (fabsf(col_rect->rect.y - plat_bottom) < STEP_HEIGHT) {
            if (col_rect->speed.y < 0.0) {
                col_rect->speed.y = 0.0;
            }

            col_rect->rect.y = plat_bottom;
        } else if (fabsf(col_bottom - platform->y) < STEP_HEIGHT) {
            if (col_rect->speed.y > 0.0) {
                col_rect->speed.y = 0.0;
            }

            col_rect->rect.y = platform->y - MARIO_HEIGHT;
        } else {
            col_rect->speed.x = 0.0;
            col_rect->rect.x = plat_right;
        }
    } else {
        if (col_rect->rect.y < platform->y && col_bottom > platform->y) {
            col_rect->speed.y = 0.0;
            col_rect->rect.y = platform->y - MARIO_HEIGHT;
        } else if (col_rect->rect.y < plat_bottom && col_bottom > plat_bottom) {
            col_rect->speed.y = 0.0;
            col_rect->rect.y = plat_bottom;
        }
    }
}
