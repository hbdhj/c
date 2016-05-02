/*
Sherlock and The Beast

Sample Input

4
1
3
5
11
Sample Output

-1
555
33333
55555533333
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
        cin >> n;
        bool print=false;
        for (int i=0; i<=n/5; i++) {
            if ((n-5*i)%3==0) {
                int n5 = n-5*i;
                int n3 = i*5;
                for (int j=0;j<n5;j++)
                    cout<<"5";
                for (int j=0;j<n3;j++)
                    cout<<"3";
                cout<<endl;
                print=true;
                break;
            }
        }
        if(!print)
            cout<<"-1"<<endl;
    }
    return 0;
}
