#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <arpa/inet.h>
#include <iostream>
using namespace std;

const char* header = "Deng Haijun 2017/05/04";

void ConvertAsciiHexToUint8Vector(std::string hex, std::vector<uint8_t> &vec) 
{
    unsigned i = 0;
    std::string nhex;
    std::string run;
    // remove the 0x/X at the head
    if (hex.length() > 1)
    {
        if(hex[0] == '0' && (hex[1]=='X' || hex[1]=='x'))
            nhex = hex.substr(2);
        else
            nhex = hex;
    }
    else
        nhex = hex;
    // return if an empty string
    if (nhex.length() ==0)
        return;
    // insert 0 if length is odd
    if (nhex.length() % 2)
        run.append(1, '0');
    run.append(nhex);
    // change to a uint8 vector
    std::vector<uint8_t> interim(run.length(), 0);
    for (i = 0; i < run.size(); i++)
    {
        if (run[i] >= '0' && run[i] <= '9')
            interim[i] = run[i] - '0';
        if (run[i] >= 'A' && run[i] <= 'F')
            interim[i] = run[i] - 'A' + 10;
           if (run[i] >= 'a' && run[i] <= 'f')
            interim[i] = run[i] - 'a' + 10;
    }
    // append to result vector
    for (i = 0; i < run.size() / 2; i++)
    {
        vec.insert(vec.end(), interim[i * 2] * 16 + interim[i * 2 + 1]);
    }
}

void print (int i) {  // function:
    std::cout << ' ' << i;
}

int main()
{
    std::vector<uint8_t> vec;
    ConvertAsciiHexToUint8Vector("0x0000123456", vec);
    for_each (vec.begin(), vec.end(), print);
    return 0;
}