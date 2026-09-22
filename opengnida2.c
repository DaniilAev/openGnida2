#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "engine.h"


/*ERRORS*/
const char common_bad_usage_err[] = "Bad usage: try the \"opengnida2 --help\"\n\0";
const char confirm_bad_usage_err[] = "Bad usage: use the \"opengnida2 --confirm [false\\true]\"\n\0";
const char undefined_err[] = "Undefined error.\n\0";

/*Inform messages*/
const char cancelled[] = "Cancelled.\n\0";
const char started[] = "Started...\n\0";
const char help[] = "Soon\n\0";
const char version[] = "OpenGnida 2\nVersion alpha 0.1\n\0";
const char done[] = "Done.\n\0";

int main(int argc, char** argv){
    int result;

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
            result = engine();
            switch (result)
            {
            case 0:
                printf("%s", done);
                exit(0);
                break;
            
            default:
                printf("%s", undefined_err);
                exit(result);
                break;
            }
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
