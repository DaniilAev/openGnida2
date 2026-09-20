#include <stdio.h>
#include <stdlib.h>
int test(){
    FILE* file;
    int result_of_operation;
    char* test = "Testing...\n";

    fprintf(stdout, "%s", test);
    result_of_operation = system("mkdir test");
    if (result_of_operation != 0){
        return 1;
    }
    file = fopen("test\\test", "w");
    if (file == NULL){
        return 2;
    }
    fwrite("kolbasa", sizeof(char) , 7, file);
    result_of_operation = ferror(file);
    if (result_of_operation != 0){
        fclose(file);
        return 3;
    }
    result_of_operation = fclose(file);
    if (result_of_operation != 0){
        return 4;
    }
    result_of_operation = remove("test\\test");
    if (result_of_operation != 0){
        return 5;
    }
    result_of_operation = system("rmdir test");
    if (result_of_operation != 0){
        return 6;
    }
    return 0;    
}