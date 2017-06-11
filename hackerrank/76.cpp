/*
Copyright 2017 <Deng Haijun>

Dashboard > Tutorials > Cracking the Coding Interview > Recursion: Davis' Staircase

Sample Input

3
1
3
7

Sample Output

1
4
44

*/

#include "./common.h"

int stairs(int n) {
    if (n < 3) {
        return n;
    } else if (n == 3) {
        return 4;
    } else {
        long first = 1;
        long second = 2;
        long third = 4;
        long ret;
        for (int i = 4; i <= n; i++) {
            ret = first + second + third;
            first = second;
            second = third;
            third = ret;
        }
        return ret;
    }
}

int main() {
    int s;
    cin >> s;
    for (int a0 = 0; a0 < s; a0++) {
        int n;
        cin >> n;
        cout << stairs(n) << endl;
    }
    return 0;
}
