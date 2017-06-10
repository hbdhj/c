/*

Copyright 2017 <Deng Haijun>

Grid Challenge

Sample Input

1
5
ebacd
fghij
olmkn
trpqs
xywuv

Sample Output

YES

*/

#include "./common.h"

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string>  x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            sort(x[i].begin(), x[i].end());
        }
        bool check  =  true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                if (x[j][i] > x[j+1][i]) {
                    check = false;
                    break;
                }
            }
        }
        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
