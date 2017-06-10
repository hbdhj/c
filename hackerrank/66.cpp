/*

Copyright 2017 <Deng Haijun>

All Competitions > Ad Infinitum18 > Minimum Height Triangle

Sample Input

2 2

Sample Output 0

2

*/

#include "./common.h"

int lowestTriangle(int base, int area) {
    // Complete this function
    if ((area*2)%base)
        return (area*2)/base+1;
    else
        return (area*2)/base;
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}
