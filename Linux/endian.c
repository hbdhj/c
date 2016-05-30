#include <stdio.h>

int main(int argc, char *argv[])
{
    int c = 1;
    if ((*(char *)&c) == 1) {
        printf("little endian\n");
    } else {
        printf("big endian\n");
    }
    return 0;
}
