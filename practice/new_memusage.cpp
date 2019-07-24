#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc < 2)
        exit(-1);
    int byte_num = atoi( argv[1] );
    
    char* c = new char[byte_num];
    printf("byte_num = %d, addr of byte_num is %p, addr of c is %p\n", byte_num, &byte_num, c);
    sleep(100);
    delete[] c;
    exit(0);
}
