#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef enum MarioConsts { MARIO_WIDTH = 35, MARIO_HEIGHT = 65, MARIO_ANIMATION_SPEED = 10, GRAVITY = 10, JUMP_SPEED = 15 }               MarioConsts;
typedef enum TXMarioFrames { MARIO_STOPPED = 0, MARIO_WALK1, MARIO_WALK2, MARIO_WALK3, MARIO_FALL, MARIO_JUMP, MARIO_DIE1, MARIO_DIE2 }   TXMarioFrames;

typedef struct Mario {
    Vector2 pos;
    Vector2 speed;
    Vector2 speedMultiplier;

    bool facingRight;
    bool powerup;

    int lives;
    int score;

    Texture2D txL;
    Texture2D txR;
    int currentAnimationFrame;
} Mario;

Mario initMario();

void unloadMarioTX(Mario mario);

#endif /* ifndef PLAYER_H */
