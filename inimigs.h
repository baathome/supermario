#ifndef INIMIGS_H
#define INIMIGS_H

#include "raylib.h"

typedef enum InimigsConsts { INIMIGS_WIDTH = 45, INIMIGS_HEIGHT = 45, INIMIGS_ANIMATION_SPEED = 10 }  InimigsConsts;
typedef enum TXInimigsStates { INIMIGS_STOPPED = 0, INIMIGS_WALK1, INIMIGS_WALK2, INIMIGS_WALK3, INIMIGS_WALK4, INIMIGS_STUN}  TXInimigsStates;

typedef struct Inimigs {
    Vector2 pos;
    Vector2 speed;
    Vector2 speedMultiplier;
    int lvl;


    bool facingRight;
    bool state;
    bool alive;
    bool angry;



    Texture2D txL;
    Texture2D txR;
    Texture2D stun;
    int currentAnimationFrame;
} Inimigs;

Inimigs initInimigs();

void unloadInimigsTX(Inimigs inimigs);

#endif /* ifndef PLAYER_H */
