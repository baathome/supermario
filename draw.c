#include "draw.h"
#include "raylib.h"

extern struct g_block_t *g_blocks;
extern struct g_block_t *g_last_block;
extern struct g_player_t g_player;

void d_DrawBlocks()
{
    struct g_block_t *block = g_blocks;

    while(block)
    {
        Color color = {.r = 255, .a = 255};
        DrawRectangle((int)block->rect.x, (int)block->rect.y, 10, 25, color);
        block = block->next;
    }
}

void d_DrawEnemies()
{

}

void d_DrawPlayer()
{
    Color color = {.g = 255, .a = 255};
    DrawRectangle((int)g_player.rect.x, (int)g_player.rect.y, 10, 25, color);
}

void d_Draw()
{
    d_DrawBlocks();
    d_DrawEnemies();
    d_DrawPlayer();
}