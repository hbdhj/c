/*
the output is 2, 5, addr, addr + 20, 5
*/
#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};
	int *ptr = (int*)(&a+1);
    printf("%d, %d, &a=%p, ptr=%p, ptr - &a = %d\n", *(a+1), *(ptr+-1), &a, ptr, ptr-((int*)&a));
	return 0;
}