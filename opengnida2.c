#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bad_usage_err[] = "Bad usage: use the \"opengnida2 --confirm [false\\true]\"";
char cancelled[] = "Cancelled.";
int main(int argc, char** argv){
    if(argc < 2){
        fprintf(stderr, "%s", bad_usage_err);
        exit(1);
    }
    if (strcmp(argv[1], "--confirm")){
        fprintf(stderr, "%s", bad_usage_err);
        exit(1);        
    }
    else{
        if (!strcmp(argv[2], "false")){
            fprintf(stdout, "%s", cancelled);
            exit(0);
        }
        if (!strcmp(argv[2], "true")){
            goto start;
        }
        fprintf(stderr, "%s", bad_usage_err);
        exit(1);
    }
    start:
    return 0;
}
