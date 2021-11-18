#ifndef G_DEFS_H
#define G_DEFS_H

#include "raylib.h"

struct g_enemy_t
{
    struct g_enemy_t *next;
    struct g_enemy_t *prev;
    Rectangle rect;
    float vel_y;
    int type;
};

enum G_BLOCK_TYPES
{
    G_BLOCK_TYPE_PLATFORM = 'P',
    G_BLOCK_TYPE_PIPE = 'C',
    G_BLOCK_TYPE_POW = 'B',
};

struct g_block_t
{
    struct g_block_t *next;
    struct g_block_t *prev;
    Rectangle rect;
    int type;
};

struct g_player_t
{
    Rectangle rect;
    float vel_x;
    float vel_y;
};


#endif