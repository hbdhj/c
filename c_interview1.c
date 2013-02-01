#include <stdio.h>
#include <unistd.h>
int main()  
{
    while(1)
    {
        fprintf(stdout,"hello-std-out\n");
        fprintf(stdout,"hello-std-out"); //\n will make fprintf flush.
        fprintf(stderr,"hello-std-err\n");
        sleep(1);
    }
    return 0;
}