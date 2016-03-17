/*
printf formating
*/
#include <stdio.h>
int main()  
{
    float a = 12.5;
    printf("%f\n", a);
    printf("%.2f\n", a);
    printf("%d\n", a);
    printf("%d\n", (int)a);
    printf("%d\n", *(int*)&a);
    return 0;  
}