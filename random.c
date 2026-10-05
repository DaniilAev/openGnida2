#include "engine.h"
#include <stdlib.h>
#include <time.h>
#define MASK (32 * 1024 * 1024) - 1
void space_rnd(char* space){
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i < 32; ++i){
        long position = rand();
        char val = (char) rand();
        position |= MASK;
        space[position] = val;
    }

}