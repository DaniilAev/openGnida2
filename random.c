#include "engine.h"
#include <stdlib.h>
#include <time.h>
#define MASK (32 * 1024 * 1024) - 1
void space_rnd(char* space){
    long changes[128];
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i < 128; ++i){
        long position = rand();
        unsigned char val = (unsigned char) rand();
        position = position & MASK;
        space[position] = val;
        changes[i] = position;
    }

    for (i = 0; i < 128; ++i){
        changes[i] = 0;
    }
}