#include <math.h>
#include "phys.h"
#include "g_defs.h"

extern struct g_block_t *g_blocks;
extern struct g_enemy_t *g_enemies;
extern struct g_player_t g_player;



void p_HandleCollisions()
{
    float abs_x_vel = fabsf(g_player.collider.vel_x);

    if(abs_x_vel > G_PLAYER_MAX_VEL_X)
    {
        g_player.collider.vel_x *= G_PLAYER_MAX_VEL_X / abs_x_vel;
    }

    g_player.collider.vel_y += G_PLAYER_GRAVITY;

    g_player.collider.rect.x += g_player.collider.vel_x;
    g_player.collider.rect.y += g_player.collider.vel_y;

    g_player.collider.vel_x *= 0.9;


    p_CollideWithBlocks(&g_player.collider);
}

void p_CollideWithBlocks(struct g_col_t *collider)
{
    struct g_block_t *block = g_blocks;
    collider->flags = 0;

    while(block)
    {
        float col_left = collider->rect.x;
        float col_right = col_left + collider->rect.width;
        float col_top = collider->rect.y;
        float col_bottom = col_top + collider->rect.height;

        float block_left = block->rect.x;
        float block_right = block_left + block->rect.width;
        float block_top = block->rect.y;
        float block_bottom = block_top + block->rect.height;

        if(col_right >= block_left && col_left <= block_right)
        {
            if(col_bottom >= block_top && col_top <= block_top)
            {
                collider->rect.y = block->rect.y - collider->rect.height;
                collider->vel_y = 0.0;
                collider->flags |= G_COL_FLAG_BOTTOM_COLLISION;
            }
            else if(col_top <= block_bottom)
            {
                if(col_bottom >= block_bottom)
                {
                    collider->rect.y = block->rect.y + block->rect.height;
                    collider->vel_y = 0.0;
                    collider->flags |= G_COL_FLAG_TOP_COLLISION;
                }
                // else
                // {
                //     collider->
                // }
            }
        }
        
        block = block->next;
    }
}