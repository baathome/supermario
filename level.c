#include "level.h"

void initPlatforms(Platform *platforms[], int nPlatforms) {
    for (int i = 0; i < nPlatforms; i++) {
        platforms[i]->start.x = -1.0;
    }
}
