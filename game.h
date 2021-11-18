#ifndef GAME_H
#define GAME_H

#include "g_defs.h"


struct g_enemy_t *g_CreateEnemy(int type, int pos_x, int pos_y, int vel_y);

void g_DestroyEnemy(struct g_enemy_t *enemy);

struct g_block_t *g_CreateBlock(float pos_x, float pos_y, int type);

void g_DestroyBlock(struct g_block_t *block);

void g_PlayerInput();

void g_EnemyImpact();

void g_PowImpact();

void g_PlayerImpact(struct g_enemy_t *enemy);




#endif