/*

Copyright 2017 <Deng Haijun>

Tutorials > 10 Days of Statistics > Day 0: Weighted Mean

Sample Input

5
10 40 30 50 20
1 2 3 4 5

Sample Output

32.0

*/

#include "./common.h"

int main() {
    int n, wi;
    cin >> n;
    vector<int> xis(n);
    int weight_total = 0;
    int value_total = 0;
    for (int i = 0; i < n; i++) {
        cin >> xis[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> wi;
        value_total += wi * xis[i];
        weight_total += wi;
    }

    printf("%.1f\n", static_cast<float>(value_total) /weight_total);

    return 0;
}
