#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    uint a = 1;
	uint b = 2;
	uint c = a - b;
	printf("%u - %u = %u\n", c);
	
    
    exit(0);
}