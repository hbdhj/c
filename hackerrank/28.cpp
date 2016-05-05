/*

Diagonal Difference

Sample Input

3
11 2 4
4 5 6
10 8 -12

Sample Output

15

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int d1 = 0;
    int d2 = 0;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
        d1+=a[a_i][a_i];
        d2+=a[a_i][n-1-a_i];
    }
    cout<<(d1>d2?(d1-d2):(d2-d1))<<endl;
    return 0;
}