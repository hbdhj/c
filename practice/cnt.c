/*
gcc program layout
gcc -c cnt.c
readelf -a cnt.o
*/

#include <stdio.h>

void f(int i)
{
    int static count = 10; 
    int a = 0;

    count = i;
    count++;
    if (count >= 20)
        goto done;
    else{
        printf("the count is lower than 20\n");
        return;
    }
done:
    printf("the count is higher than 20\n");
    a = 20;
    printf("a is : %d\n", a);

    return;
}

int main(void)
{
    int i;
    scanf("%d", &i);
    f(i);
    return 0;
}
