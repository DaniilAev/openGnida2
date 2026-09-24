#include <stdio.h>
#include <stdlib.h>
int test(){
    FILE* file;
    int result_of_operation;
    char* test = "Testing...\n";
    char* test_compl = "Test complete\n";
    char* space;

    fprintf(stdout, "%s", test);

    /*Folder creting test*/
    result_of_operation = system("mkdir test");
    if (result_of_operation != 0){
        return 1;
    }

    /*Creating file test*/
    file = fopen("test\\test", "w");
    if (file == NULL){
        return 2;
    }

    /*Mem allocating test*/
    space = (char*)malloc(32768);
    if (space == NULL){
        return 7;
    }

    /*Writing test*/
    fwrite(space, sizeof(char) , 32768, file);
    free(space);
    result_of_operation = ferror(file);
    if (result_of_operation != 0){
        fclose(file);
        return 3;
    }

    /*File closing test*/
    result_of_operation = fclose(file);
    if (result_of_operation != 0){
        return 4;
    }

    /*File removing test*/
    result_of_operation = remove("test\\test");
    if (result_of_operation != 0){
        return 5;
    }

    /*Folder deleting test*/
    result_of_operation = system("rmdir test");
    if (result_of_operation != 0){
        return 6;
    }

    /*Successfuly*/
    fprintf(stdout, "%s", test_compl);
    return 0;    
}