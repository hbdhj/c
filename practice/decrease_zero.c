#include <stdio.h>  

int main()  
{  
    int zero = 0;  
    printf("signed zero = %d\n", zero);
	zero--;
	printf("signed zero = %d\n", zero);
	unsigned int unsign_zero = 0;  
    printf("signed zero = %u\n", unsign_zero);
	unsign_zero--;
	printf("signed zero = %u\n", unsign_zero);
	return 0;  
}  