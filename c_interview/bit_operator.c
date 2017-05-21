//#include <string>
#include <stdio.h>
#include <arpa/inet.h>

//using namespace std;

int main()
{
	short i = 0xa027;
	printf("sizeof(short) = %d, 0x%x & 0xff = 0x%x\n", sizeof(short), i, 0xff & i);
	printf("3&2 = %d, 3&1 = %d, 2&2 = %d, 2&1 = %d, 1&1 = %d\n", 3&2, 3&1, 2&2, 2&1, 1&1);
	printf("3|2 = %d, 3|1 = %d, 2|2 = %d, 2|1 = %d, 1|1 = %d\n", 3|2, 3|1, 2|2, 2|1, 1|1);
	printf("3^2 = %d, 3^1 = %d, 2^2 = %d, 2^1 = %d, 1^1 = %d\n", 3^2, 3^1, 2^2, 2^1, 1^1);
	return 0;
}