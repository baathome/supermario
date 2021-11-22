#include "player.h"
#include "raylib.h"

Mario initMario() {
    Mario mario;

    mario.pos.x = 5;
    mario.pos.y = 5;
    mario.speed.x = 0;
    mario.speed.y = 0;
    //mario.speedMultiplier.x = MARIO_SPEED;
    //mario.speedMultiplier.y = 0;

    mario.facingRight = true;
    mario.powerup = false;

    mario.lives = 3;
    mario.score = 0;

    mario.txR = LoadTexture("resources/marioRight.png"); //TODO: add check to see if screen is init
    mario.txL = LoadTexture("resources/marioLeft.png");

    mario.currentAnimationFrame = MARIO_STOPPED;

    return mario;
}

void unloadMarioTX(Mario mario) {
    UnloadTexture(mario.txL);
    UnloadTexture(mario.txR);
}
