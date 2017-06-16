/*
Copyright 2017 <Deng Haijun>

All Competitions > Week of Code 33 > Transform to Palindrome 

Sample Input 0

10 7 6
1 3
5 7
3 5
2 6
2 4
8 4
10 9
1 9 2 3 10 3

Sample Output 0

5

Sample Input 1

10 8 15
1 2
1 3
2 7
3 1
4 5
6 8
9 6
10 5
1 4 5 7 9 8 1 3 10 4 5 10 2 7 8

Sample Output 1

10

*/

#include "./common.h"

int main() {
    int n;
    int k;
    int m;
    cin >> n >> k >> m;
    map<int, int> replaces;
    for (int a0 = 0; a0 < k; a0++) {
        int x;
        int y;
        cin >> x >> y;
        replaces[max(x, y)] = min(x, y);
    }
    vector<int> a(m);
    for (int a_i = 0; a_i < m; a_i++) {
       cin >> a[a_i];
    }
    bool swap = false;
    do {
        swap = false;
        for (map<int, int>::iterator it=replaces.begin(); it!=replaces.end(); ++it) {
            if ((replaces.find(it->second))!=replaces.end() && replaces[it->second] < it->second) {
                it->second = replaces[it->second];
                swap = true;
            }
        }
    } while(swap);
    vector<int> trans = a;
    for (int a_i = 0; a_i < m; a_i++) {
        if (replaces.find(a[a_i])!=replaces.end()) {
            trans[a_i] = replaces[trans[a_i]];
        }
        cout<<trans[a_i]<<" ";
    }
    cout<<endl;
    map<int, int> counts;
    for (int a_i = 0; a_i < m; a_i++) {
        if (counts.find(trans[a_i]) != counts.end())
            counts[trans[a_i]]++;
        else
            counts[trans[a_i]] = 1;
    }
    int max_odd = 0;
    int even_total = 0;
    for (map<int, int>::iterator it=counts.begin(); it!=counts.end(); ++it) {
        if (it->second % 2) {
            if (it->second>max_odd)
                max_odd = it->second;
        } else {
            even_total += it->second;
        }
    }
    cout<<even_total<<", "<<max_odd<<endl;
    return 0;
}
