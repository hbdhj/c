/*
Angry Professor

Sample Input
2
4 3
-1 -3 4 2
4 2
0 -1 2 1

Sample Output
YES
NO
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
        }
        int ontime = 0;
        for(int a_i = 0;a_i < n;a_i++){
            if( a[a_i] <= 0)
                ontime++;
        }
        if(ontime>=k)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
