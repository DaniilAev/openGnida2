#include "engine.h"
#include <stdlib.h>
#include <time.h>
void space_rnd(char* space){
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i < 32; ++i){
        space[(rand() | 33554431)] = (char)rand();
    }
    
}