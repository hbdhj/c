#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char src[5] = {2,3,5,7,11};
    char dst[5];
    memcpy(dst, src, sizeof(src));
    printf("src = %p, dst = %p sizeof(src) = %d, sizeof(dst) = %d ", src, dst, sizeof(src), sizeof(dst));
    for(int i = 0; i<sizeof(dst); i++)
        printf("dst[%d] = %d ", i, dst[i]);
    printf("\n");
    return 0;
}

