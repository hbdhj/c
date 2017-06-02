#include <iostream>
using namespace std;
#define prod(a,b) ((a>b)?a*a:b*b) 
int main() {
    int p=0,q=-1;
    printf("%d\n", prod(p++, q++));
    return 0;
}

