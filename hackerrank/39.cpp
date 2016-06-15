/*
Flipping bits

Sample Input

3
2147483647
1
0

Sample Output

2147483648
4294967294
4294967295
*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<unsigned int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    for(int arr_i = 0; arr_i < n; arr_i++){
       cout << 0xFFFFFFFF - arr[arr_i] <<endl;
    }
    return 0;
}
