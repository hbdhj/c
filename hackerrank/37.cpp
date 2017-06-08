/*
Copyright 2017 <Deng Haijun>

Stock Maximize
*/

#include "./common.h"

#define MAX_N 50008

int64 share[MAX_N];
bool sell[MAX_N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, N;
    cin >> T;
    while (T--) {
        int64 max_share = 0;
        int64 profit = 0;
        int64 cnt = 0;
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
