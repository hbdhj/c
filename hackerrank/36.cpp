/*
Copyright 2017 <Deng Haijun>
The Coin Change Problem
*/

#include "./common.h"

#define MAX_N 256
#define MAX_M 64

int64 f[MAX_N];
int c[MAX_M];
int m, n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> c[i];

    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (j >= c[i]) {
                f[j] += f[j - c[i]];
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}
