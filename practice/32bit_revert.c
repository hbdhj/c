#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <arpa/inet.h>
#include <iostream>
#include <bitset>
using namespace std;

/*unsigned int bit_revert(unsigned int input)
{
    bitset<32> bitvec1(input);
    bitset<32> bitvec2;
    for(int i=0; i<32; i++)
        bitvec2[i]=bitvec1[31-i];
    return bitvec2.to_ulong();
}*/

unsigned int bit_revert(unsigned int input)
{
    char bits[32];
    unsigned int ret=0;
	
    for(int i=0; i<32; i++)
    {
        ret+=(((input<<i)&(1<<31))>>(31-i));
    }
    bitset<32> bitvec1(input);
    bitset<32> bitvec2(ret);
    cout <<"input bin : " <<bitvec1 <<endl;
    cout <<"output bin : " <<bitvec2 <<endl;    
    return ret;
}
int main()
{
    unsigned int input = 0x01020304;
    unsigned int output = bit_revert(input);
    unsigned int input1 = 0x80000000;
    unsigned int output1 = bit_revert(input1);
    unsigned int input2 = 0x00000001;
    unsigned int output2 = bit_revert(input2);
    unsigned int input3 = 0xffffffff;
    unsigned int output3 = bit_revert(input3);
    return 0;
}