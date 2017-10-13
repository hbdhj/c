#include <stdio.h>

int main() {
    char *ptr;
    if ((ptr = (char *)malloc(0)) == NULL) {
        puts("Got a null pointer");
    }
    else {
        //puts("Got a valid pointer");
        printf("Got a valid pointer %p\n", ptr);
        free(ptr);
    }
    return 0;
}
