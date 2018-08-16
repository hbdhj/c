#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc < 2)
        exit(-1);
    int byte_num = atoi( argv[1] );
    
    printf("byte_num = %d\n", byte_num);
    char* c = new char[byte_num];
    sleep(100);
    delete[] c;
    exit(0);
}
