/*
This code file is for gdb study.
Please compile it with g++ -g
*/

#include <iostream>

using namespace std;

int test()
{
    int* output=new int[5];
    for(int i=0;i<10000;i++)
        output[i]=1;
    printf("%d\n", output[7]);
	return 0;
}

int main()
{
	test();
	return 0;
}
