#include <stdio.h>
int main()
{
    int i=43;
    printf("%d\n",printf("%d",printf("%d",i))); //printf will return the length
    printf("%d\n",printf("%d\n",printf("%d\n",i))); //Guess what this will return 43\n3\n2\n
    return 0;
}