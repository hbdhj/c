/*

Copyright 2017 <Deng Haijun>

Tutorials > 10 Days of Statistics > Day 1: Quartiles

Sample Input

9
3 7 8 5 12 14 21 13 18

Sample Output

6
12
16

*/

#include "./common.h"

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> xis(n);
    for (int i = 0; i < n; i++) {
        cin >> xis[i];
    }
    sort(xis.begin(), xis.end());
    if (n%2) {
        if ((n/2)%2)
            cout << xis[n/4] << endl;  // 1 of 7
        else
            cout << (xis[n/4-1] + xis[n/4])/2 << endl;  // 1 and 2 of 9
        cout << xis[n/2] << endl;  // 4 of 9 or 3 of 7
        if ((n/2)%2)
            cout <<xis[n/4+n/2+1] << endl;  // 5 of 7
        else
            cout <<(xis[n/4+n/2]+xis[n/4+n/2+1])/2 << endl;  // 7 and 8 of 9
    } else {
        if ((n/2)%2)
            cout << xis[n/4] << endl;  // 2 of 10
        else
            cout <<(xis[n/4-1]+xis[n/4])/2 << endl;  //  1 and 2 of 8
        cout << (xis[n/2]+xis[n/2-1])/2 << endl;  // 3 - 4 of 8 or 4 - 5 of 10
        if ((n/2)%2)
            cout << xis[n/4+n/2] << endl;  // 7 of 10
        else
            cout << (xis[n/4+n/2-1]+xis[n/4+n/2])/2 << endl;  // 5 and 6 of 8
    }
    return 0;
}
