#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "engine.h"


/*ERRORS*/
const char common_bad_usage_err[] = "Bad usage: try the \"opengnida2 --help\"\n\0";
const char confirm_bad_usage_err[] = "Bad usage: use the \"opengnida2 --confirm [false\\true]\"\n\0";
const char undefined_err[] = "Undefined error.\n\0";
const char dir_cre_folder_err[] = "Unable to create a folder\n\0";
const char file_op_err[] = "Unable to open a file\n\0";
const char write_err[] = "Unable to write data to the file\n\0";
const char close_err[] = "Unable to close the file\n\0";
const char remove_err[] = "Unable to delete the file\n\0";
const char fol_rem_err[] = "Unable to remove the folder\n\0";
const char alloc_err[] = "Unable to allocate the memory\n\0";

/*Inform messages*/
const char cancelled[] = "Cancelled.\n\0";
const char started[] = "Started...\n\0";
const char help[] = "Help: --help\nVersion: --version\nStart: --confirm [true/false]\nTry to find other information on github.com/daniilaev/openGnida2\0";
const char version[] = "OpenGnida 2\nVersion 1.0\nSourse: github.com/daniilaev/openGnida2\n\0";
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
            case 1:
                sprintf(stderr, "%s", dir_cre_folder_err);
                exit(1);
                break;
            case 2:
                sprintf(stderr, "%s", file_op_err);
                exit(1);
                break;
            case 3:
                sprintf(stderr, "%s", dir_cre_folder_err);
                exit(1);
                break; 
            case 4:
                sprintf(stderr, "%s", close_err);
                exit(1);
                break;
            case 5:
                sprintf(stderr, "%s", remove_err);        
                exit(1);
                break;               
            case 6:
                sprintf(stderr, "%s", fol_rem_err);
                exit(1);
                break;
            case 7:
                sprintf(stderr, "%s", alloc_err);
                exit(1);
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
