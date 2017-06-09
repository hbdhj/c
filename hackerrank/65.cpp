/*

Copyright 2017 <Deng Haijun>

Tutorials > 10 Days of Statistics > Day 1: Interquartile Range

Sample Input

6
6 12 8 10 20 16
5 4 3 2 1 5

Sample Output

9.0

*/

#include "./common.h"

int findInVecPair(vector<pair<int, int> > &p, int n) {
    for (vector<pair<int, int> >::iterator it = p.begin();
                                           it != p.end(); it++) {
        if (n < (*it).second)
            return (*it).first;
        else
            n -= (*it).second;
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> f(n);
    vector<pair<int, int> > p(n);
    int f_total = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
        f_total += p[i].second;
    }
    sort(p.begin(), p.end());
    /*for (int i = 0; i < n; i++) {
        cout << p[i].first << " " << p[i].second <<endl;
    }*/
    int q1_i_1, q1_i_2;
    int q3_i_1, q3_i_2;
    if (f_total%2) {
        if ((f_total/2)%2) {
            q1_i_1 = q1_i_2 = f_total/4;  // 1 of 7
            q3_i_1 = q3_i_2 = f_total/4+f_total/2+1;  // 5 of 7
        } else {
            q1_i_1 = f_total/4-1;  // 1 of 9
            q1_i_2 = f_total/4;    // 2 of 9
            q3_i_1 = f_total/4+f_total/2;    // 7 of 9
            q3_i_2 = f_total/4+f_total/2+1;  // 8 of 9
        }
    } else {
        if ((f_total/2)%2) {
            q1_i_1 = q1_i_2 = f_total/4;  // 2 of 10
            q3_i_1 = q3_i_2 = f_total/4+f_total/2;  // 7 of 10
        } else {
            q1_i_1 = f_total/4-1;  // 1 of 8
            q1_i_2 = f_total/4;    // 2 of 8
            q3_i_1 = f_total/4+f_total/2-1;    // 5 of 8
            q3_i_2 = f_total/4+f_total/2;  // 6 of 8
        }
    }
    // cout << f_total << ", " << q1_i_1 << ", "<< q1_i_2 
    //      << ", " << q3_i_1 << ", " << q3_i_2 <<endl;
    float q1, q3;
    if (q1_i_1 == q1_i_2) {
        q1 = findInVecPair(p, q1_i_1);
    } else {
        q1 = (findInVecPair(p, q1_i_1) + findInVecPair(p, q1_i_2))/2;
    }
    if (q3_i_1 == q3_i_2) {
        q3 = findInVecPair(p, q3_i_1);
    } else {
        q3 = (findInVecPair(p, q3_i_1) + findInVecPair(p, q3_i_2))/2;
    }
    // printf("%.1f, %.1f, %.1f\n", q1, q3, q3 - q1);
    printf("%.1f\n", q3 - q1);
    return 0;
}
