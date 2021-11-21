#ifndef INIMIGS_H
#define INIMIGS_H

#include "raylib.h"

typedef enum InimigsConsts { Inimigs_WIDTH = 25, Inimigs_HEIGHT = 45, Inimigs_ANIMATION_SPEED = 10 }  InimigsConsts;
typedef enum TXInimigsStates { Inimigs_STOPPED = 0, Inimigs_WALK1, Inimigs_WALK2, Inimigs_WALK3, Inimigs_WALK4,}  TXInimigsStates;

typedef struct Inimigs {
    Vector2 pos;
    Vector2 speed;
    Vector2 speedMultiplier;



    bool facingRight;
    bool state;
    bool alive;
    bool angry;

    int lives;

    Texture2D txL;
    Texture2D txR;
    int currentAnimationFrame;
} Inimigs;

Inimigs initInimigs();

void unloadInimigsTX(Inimigs inimigs);

#endif /* ifndef PLAYER_H */
