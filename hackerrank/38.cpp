/*
Copyright 2017 <Deng Haijun>

Arrays - DS
*/

#include "./common.h"

using std::vector;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int arr_i = 0; arr_i < n; arr_i++) {
       cin >> arr[arr_i];
    }
    for (int arr_i = n-1; arr_i >= 0; arr_i--) {
       cout << arr[arr_i] << " ";
    }
    return 0;
}
