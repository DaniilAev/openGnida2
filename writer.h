#ifndef WRITER
    #ifdef _WIN64
        #define WRITER
        #include <windows.h>
        #define writer(fd, buf, n) WriteFile(fd, buf, n, 0, 0)
    #endif
    #ifdef __unix__
        #define WRITER
        #include <unistd.h>
        #define writer(fd, buf, n) write(fd, buf, n, 0, 0)
    #endif
#endif