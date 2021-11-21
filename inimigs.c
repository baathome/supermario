#include "inimigs.h"
#include "raylib.h"

Inimigs initInimigs() {
    Inimigs inimigs;

    inimigs.pos.x = 5;
    inimigs.pos.y = 2;
    inimigs.speed.x = 0;
    inimigs.speed.y = 0;
    inimigs.speedMultiplier.x = 0;
    inimigs.speedMultiplier.y = 0;

    inimigs.facingRight = true;

    inimigs.state = true; // walking
    inimigs.alive = true; //alive
    inimigs.angry = true;//not running

    inimigs.txR = LoadTexture("resources/lvl1Right.png"); //TODO: add check to see if screen is init
    inimigs.txL = LoadTexture("resources/lvl1left.png");
    inimigs.stun = LoadTexture("resources/tartarugamorta.png");
    inimigs.currentAnimationFrame = INIMIGS_STOPPED;

    return inimigs;
}

void unloadInimigsTX(Inimigs inimigs) {
    UnloadTexture(inimigs.txL);
    UnloadTexture(inimigs.txR);
}
