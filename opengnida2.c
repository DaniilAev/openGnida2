#include <stdio.h>
#include <stdlib.h>
char bad_udage_msg[] = "Bad usage: use the \"opengnida --confirm [false\\true]\"";
int main(int argc, char** argv){
    if(argc < 2){
        fprintf(stderr, "%s", bad_udage_msg);
        exit(1);
    }
    return 0;
}