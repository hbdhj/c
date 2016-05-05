/*

Vector-Sort

Sample Input

5
1 6 10 8 4
Sample Output

1 4 6 8 10

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
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    sort(arr.begin(), arr.end());
    for(int arr_i = 0; arr_i < n-1; arr_i++){
       cout << arr[arr_i] <<" ";
    }
    cout << arr[n-1] <<endl;
    return 0;
}
