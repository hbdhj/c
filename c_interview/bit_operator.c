//#include <string>
#include <stdio.h>
#include <arpa/inet.h>

//using namespace std;

int main()
{
	short i = 0xa027;
	printf("sizeof(short) = %d, 0x%x & 0xff = 0x%x\n", sizeof(short), i, 0xff & i);
	return 0;
}