//#include <string>
#include <stdio.h>
#include <arpa/inet.h>

//using namespace std;

int main()
{
	short i = 10;
	printf("0x%x\n", i);
	printf("htons(0x%x) = 0x%x\n", i, htons(i));
	printf("htonl(0x%x) = 0x%x\n", i, htonl(i));
	printf("htonl(int(0x%x)) = 0x%x\n", i, htonl(int(i)));
	printf("htonl(htons(0x%x)) = 0x%x\n", i, htonl(htons(i)));
	printf("int(htons(0x%x)) = 0x%x\n", i, int(htons(i)));
	return 0;
}