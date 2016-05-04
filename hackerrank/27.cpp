/*

A Very Big Sum

Sample Input
5
1000000001 1000000002 1000000003 1000000004 1000000005

Output
50000000155000000015.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
        sum+=arr[arr_i];
    }
    cout<<sum<<endl;
    return 0;
}