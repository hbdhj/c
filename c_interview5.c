/*
Potential core for scanf with limit length string
*/
#include <stdio.h>
int main()  
{      
    char str[80];
    printf("Enter the string:");
    scanf("%s",str);    //will not promise the length < 80
    printf("You entered:%s\n",str);
    return 0;
}