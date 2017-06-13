/*
Copyright 2017 <Deng Haijun>

All Competitions > Week of Code 33 > Twin Arrays 

Sample Input

5
1 6 
2 7
3 8
4 9
2 6

Sample Output

2 4

Sample Input

10
1 17
5 13
7 12
5 17
5 12
2 17
1 18
8 13
2 15
5 20

Sample Output

11 11

*/

#include "./common.h"

int twinArrays(vector <int> ar1, vector <int> ar2) {
    // Complete this function
    vector<pair<int, int> > ar_pos1(ar1.size());
    vector<pair<int, int> > ar_pos2(ar2.size());
    for (int i = 0; i < ar1.size(); i++) {
        ar_pos1[i].first = ar1[i];
        ar_pos1[i].second = i;
    }
    for (int i = 0; i < ar2.size(); i++) {
        ar_pos2[i].first = ar2[i];
        ar_pos2[i].second = i;
    }
    sort(ar_pos1.begin(), ar_pos1.end());
    sort(ar_pos2.begin(), ar_pos2.end());
    if (ar_pos1[0].second != ar_pos2[0].second)
        return ar_pos1[0].first+ar_pos2[0].first;
    else
        return min(ar_pos1[1].first + ar_pos2[0].first,
                   ar_pos1[0].first + ar_pos2[1].first);
}

int main() {
    int n;
    cin >> n;
    vector<int> ar1(n);
    for (int ar1_i = 0; ar1_i < n; ar1_i++) {
       cin >> ar1[ar1_i];
    }
    vector<int> ar2(n);
    for (int ar2_i = 0; ar2_i < n; ar2_i++) {
       cin >> ar2[ar2_i];
    }
    int result = twinArrays(ar1, ar2);
    cout << result << endl;
    return 0;
}
