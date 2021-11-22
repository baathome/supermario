#ifndef LEVEL_H
#define LEVEL_H


#include "raylib.h"
#include "player.h"

#define MAX_PLATFORMS    2000
#define MAX_INIMIGS 200
#define MAX_GAME_OBJECTS 300
#define PIXELS_BY_LINE   25.0
#define PIXELS_BY_COLUMN 10.0

typedef enum GameObjectType { CANO_D, CANO_E, SPAWN, POWERUP } GameObjectType;

typedef struct GameObject {
    Vector2 pos;
    int type;
    Texture2D tx;
} GameObject;

void initPlatforms(Rectangle platforms[], int nPlatforms);

void initGameObjects(GameObject objects[], int nGameObjects);

int getNextPlatformIndex(Rectangle platforms[], int nPlatforms);

int getNextGameObjectIndex(GameObject objects[], int nGameObjects);

int collisionCheckMario(Mario mario, Rectangle platforms[], int nPlatforms);

Rectangle *collisionCheck(Rectangle *rect, Rectangle platforms[], int nPlatforms);

void hitPlatform(ColRectangle *col_rect, Rectangle *platform);

//void loadLevel(int currentLevel, Mario *mario, Platform *platforms, );

#endif /* ifndef LEVEL_H */
