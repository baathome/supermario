#include "level.h"
#include <stdio.h>

void initPlatforms(Rectangle platforms[], int nPlatforms) {
    for (int i = 0; i < nPlatforms; i++) {
        platforms[i].height = -1.0;
        printf("i %d - %f\n", i, platforms[i].height);
    }
}

int getNextPlatformIndex(Rectangle platforms[], int nPlatforms) {
    int i = 0;

    while (i < nPlatforms) {
        if (platforms[i].height == -1.0) return i;

        //printf("\ni %d - %f\n", i, platforms[i].height);
        //getchar();
        i++;
    }
    return i;
}
