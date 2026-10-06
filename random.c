#include "engine.h"
#include <stdlib.h>
#include <time.h>
#define MASK (32 * 1024 * 1024 - 1)
void space_rnd(char* space){
    int* int_space = (int*)space;
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i < (MASK >> 2); ++i){
        int_space[i] = rand();
    }


}