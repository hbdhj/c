/*
The Maximum Subarray

Sample Input

2
4
1 2 3 4
6
2 -1 2 3 4 -5

Sample Output

10 10
10 11
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
        }
        int cs = 0;
        int max_cs = 0;
        int ncs = 0;
        int max_ncs = 0;
        for(int a_i = 0;a_i < n;a_i++){
            if (a[a_i]>0) {
                ncs += a[a_i];
                cs += a[a_i];
            } else {
                ncs = a[a_i];
                cs = a[a_i];
            }
            //if (cs<0)
            //    cs = 0;
            if (max_cs < cs)
                max_cs = cs;
            if (max_ncs < ncs)
                max_ncs = ncs;
        }
        cout<<max_cs<<" "<<max_ncs<<endl;
    }
    return 0;
}
