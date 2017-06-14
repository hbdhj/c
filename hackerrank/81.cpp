/*
Copyright 2017 <Deng Haijun>

Dashboard > Data Structures > Arrays > 2D Array - DS 

Sample Input

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

Sample Output

19

*/

#include "./common.h"

int main() {
    const int matrix_size = 6;
    vector< vector<int> > arr(matrix_size, vector<int>(matrix_size));
    for (int arr_i = 0; arr_i < matrix_size; arr_i++) {
       for (int arr_j = 0; arr_j < matrix_size; arr_j++) {
          cin >> arr[arr_i][arr_j];
       }
    }
    int max = -9 * 7;
    for (int arr_i = 1; arr_i < matrix_size - 1; arr_i++) {
        for (int arr_j = 1; arr_j < matrix_size - 1; arr_j++) {
            int sum = arr[arr_i-1][arr_j-1] + arr[arr_i-1][arr_j] + arr[arr_i-1][arr_j+1]
                                            + arr[arr_i][arr_j]
                    + arr[arr_i+1][arr_j-1] + arr[arr_i+1][arr_j] + arr[arr_i+1][arr_j+1];
            if (sum > max)
                max = sum;
        }
    }
    cout << max << endl;
    return 0;
}