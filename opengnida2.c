#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "writer.h"



const char common_bad_usage_err[] = "Bad usage: try the \"opengnida2 --help\0";
const char confirm_bad_usage_err[] = "Bad usage: use the \"opengnida2 --confirm [false\\true]\"\0";
const char cancelled[] = "Cancelled.";
const char started[] = "Started...";
const char help[] = "Soon";
const char version[] = "OpenGnida 2\nVersion alpha 0.1";



int main(int argc, char** argv){
    if(argc < 2){
        fprintf(stderr, "%s", common_bad_usage_err);
        exit(1);
    }
    else if (!strcmp(argv[1], "--confirm")){
        if (argc < 3){
            fprintf(stderr, "%s", confirm_bad_usage_err);
            exit(1);
        }
        else if (!strcmp(argv[2], "false")){
            fprintf(stdout, "%s", cancelled);
            exit(0);
        }
        else if (!strcmp(argv[2], "true")){
            fprintf(stdout, "%s", started);
            exit(0);
        }
        fprintf(stderr, "%s", confirm_bad_usage_err);
        exit(1);
    }
    else if (!strcmp(argv[1], "--help")){
        fprintf(stdout, "%s", help);
        exit(0);
    }
    else if (!strcmp(argv[1], "--version")){
        fprintf(stdout, "%s", version);
    }
    else{
        fprintf(stderr, "%s", common_bad_usage_err);
        exit(1);
    }
    return 0;
}
