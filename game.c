#include <stddef.h>
#include <stdlib.h>
#include "raylib.h"
#include "game.h"

struct g_enemy_t *g_enemies = NULL;
struct g_enemy_t *g_last_enemy = NULL;

struct g_block_t *g_blocks = NULL;
struct g_block_t *g_last_block = NULL;

struct g_player_t g_player;


struct g_enemy_t *g_CreateEnemy(int type, int pos_x, int pos_y, int vel_y)
{
    
}

void g_DestroyEnemy(struct g_enemy_t *enemy)
{

}

struct g_block_t *g_CreateBlock(float pos_x, float pos_y, int type)
{
    struct g_block_t *block;
    block = calloc(1, sizeof(struct g_block_t));

    block->type = type;
    block->rect.x = pos_x;
    block->rect.y = pos_y;

    if(!g_blocks)
    {
        g_blocks = block;
    }
    else 
    {
        g_last_block->next = block;
        block->prev = g_last_block;
    }
    g_last_block = block;

    return block;
}

void g_DestroyBlock(struct g_block_t *block)
{
    if(block)
    {
        if(!block->prev)
        {
            g_blocks = block->next;
        }
        else
        {
            block->prev->next = block->next;
        }

        if(block->next)
        {
            block->next->prev = block->prev;
        }
        else
        {
            g_last_block = block->prev;
        }

        free(block);
    }
}

void g_PlacePlayer(float pos_x, float pos_y)
{
    g_player.rect.x = pos_x;
    g_player.rect.y = pos_y;
}

void g_PlayerInput()
{
    
}

void g_EnemyImpact()
{

}

void g_PowImpact()
{

}

void g_PlayerImpact(struct g_enemy_t *enemy)
{

}

void g_GameMain()
{
    g_PlayerInput();
}