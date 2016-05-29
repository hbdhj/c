/*
Stock Maximize
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 50008

long long share[MAX_N];
bool sell[MAX_N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, N;
    cin >> T;
    while (T--) {
        long long max_share = 0;
        long long profit = 0;
        long long cnt = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> share[i];
        max_share = share[N - 1];
        for (int i = N - 1; i >= 0; i--) {
            sell[i] = share[i] >= max_share;
            max_share = max(max_share, share[i]);
        }
        /*
        for (int i = 0; i < N; i++) {
            cout<<sell[i]<<" ";
        }
        cout<<endl;
        */
        for (int i = 0; i < N; i++) {
            if (sell[i]) {
                profit += cnt * share[i];
                cnt = 0;
            } else {
                profit -= share[i];
                cnt += 1;
            }
        }
        cout << profit << endl;
    }
    return 0;
}
