#include "inimigs.h"
#include "raylib.h"

Inimigs initInimigs() {
    Inimigs inimigs;

    inimigs.pos.x = 10;
    inimigs.pos.y = 10;
    inimigs.speed.x = 0;
    inimigs.speed.y = 0;
    inimigs.speedMultiplier.x = 3;
    inimigs.speedMultiplier.y = 3;

    inimigs.facingRight = true;

    inimigs.lives = 1;
    inimigs.txR = LoadTexture("resources/lvl1Right.png"); //TODO: add check to see if screen is init
    inimigs.txL = LoadTexture("resources/lvl1left.png");

    inimigs.currentAnimationFrame = Inimigs_STOPPED;

    return inimigs;
}

void unloadInimigsTX(Inimigs inimigs) {
    UnloadTexture(inimigs.txL);
    UnloadTexture(inimigs.txR);
}
