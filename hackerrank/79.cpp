/*

Copyright 2017 <Deng Haijun>

Dashboard > Algorithms > Warmup > Compare the Triplets 

Sample Input

5 6 7
3 6 10

Sample Output

1 1 

*/

#include "./common.h"

vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2) {
    // Complete this function
    int a = 0;
    int b = 0;
    if (a0 > b0) {
        a++;
    } else if (a0 < b0) {
        b++;
    }
    if (a1 > b1) {
        a++;
    } else if (a1 < b1) {
        b++;
    }
    if (a2 > b2) {
        a++;
    } else if (a2 < b2) {
        b++;
    }
    vector<int> ret(2);
    ret[0] = a;
    ret[1] = b;
    return ret;
}

int main() {
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    vector < int > result = solve(a0, a1, a2, b0, b1, b2);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}