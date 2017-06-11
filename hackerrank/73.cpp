/*
Copyright 2017 <Deng Haijun>

All Competitions > Week of Code 32 > Fight the Monsters! 

Sample Input 0

7 8 6
16 19 7 11 23 8 16

Sample Output 0

4

*/

#include "./common.h"

int getMaxMonsters(int n, int hit, int t, vector < int > h) {
    // Complete this function
    sort(h.begin(), h.end());
    int c = 0;
    int i = 0;
    while (t && i < n) {
        if (((h[i] + hit - 1)/hit) <= t) {
            t -= (h[i] + hit - 1)/hit;
            c++;
            i++;
        } else {
            t = 0;
        }
    }
    return c;
}

int main() {
    int n;
    int hit;
    int t;
    cin >> n >> hit >> t;
    vector<int> h(n);
    for (int h_i = 0; h_i < n; h_i++) {
       cin >> h[h_i];
    }
    int result = getMaxMonsters(n, hit, t, h);
    cout << result << endl;
    return 0;
}