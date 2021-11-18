#include "level.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>

extern struct g_block_t *g_blocks;

void l_LoadLevel(char *level_name)
{
    void *buffer;
    long buffer_size;
    FILE *file = fopen(level_name, "r");

    fseek(file, 0, SEEK_END);
    buffer_size = ftell(file);
    rewind(file); 

    buffer = calloc(1, buffer_size);
    fread(buffer, 1, buffer_size, file);
    fclose(file);

    l_ClearLevel();

    char *data = buffer;
    int row = 0;
    int col = 0;

    for(int index = 0; index < buffer_size; index++)
    {
        if(data[index] == '\n')
        {
            col = 0;
            row++;
        }
        else
        {
            switch(data[index])
            {
                case 'p':
                    g_CreateBlock((float)col * L_LEVEL_COL_WIDTH, (float)row * L_LEVEL_ROW_HEIGHT, 0);
                break;

                case 'm':
                    g_PlacePlayer((float)col * L_LEVEL_COL_WIDTH, (float)row * L_LEVEL_ROW_HEIGHT);
                break;
            }

            col++;
        }
    }

    free(buffer);
}

void l_ClearLevel()
{
    struct g_block_t *block = g_blocks;

    while(block)
    {
        struct g_block_t *next_block = block->next;
        g_DestroyBlock(block);
        block = next_block;
    }
}