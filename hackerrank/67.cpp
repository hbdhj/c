/*

Copyright 2017 <Deng Haijun>

Tutorials > 10 Days of Statistics > Day 1: Standard Deviation 

Sample Input

5
10 40 30 50 20

Sample Output

14.1

*/

#include "./common.h"

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> x(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        total += x[i];
    }
    float mean = float(total) / n;
    float dev = 0;
    for (int i = 0; i < n; i++) {
        dev += (x[i] - mean)*(x[i] - mean);
    }
    printf("%.1f\n", sqrt(dev / n));
    return 0;
}
