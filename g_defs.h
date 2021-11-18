#ifndef G_DEFS_H
#define G_DEFS_H

#include "raylib.h"

enum G_COL_FLAGS
{
    G_COL_FLAG_TOP_COLLISION = 1,
    G_COL_FLAG_LEFT_COLLISION = 1 << 1,
    G_COL_FLAG_BOTTOM_COLLISION = 1 << 2,
    G_COL_FLAG_RIGHT_COLLISION = 1 << 3
};
struct g_col_t
{
    Rectangle rect;
    float vel_x;
    float vel_y;
    int flags;
};

struct g_enemy_t
{
    struct g_enemy_t *next;
    struct g_enemy_t *prev;
    struct g_col_t collider;
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
    int move_flags;
    struct g_col_t collider;
};

#define G_PLAYER_VEL_X_INCREMENT 0.6
#define G_PLAYER_MAX_VEL_X 6.0
#define G_PLAYER_GRAVITY 0.5
#define G_PLAYER_JUMP_VEL 13.0
#define G_PLAYER_WIDTH 35.0
#define G_PLAYER_HEIGHT 70.0

#endif