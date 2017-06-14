/*
Copyright 2017 <Deng Haijun>

Simple Array Sum

Sample Input:
6
1 2 3 4 10 11

Sample Output:
31
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <vector>

int main() {
    int n;
    int ret = 0;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int arr_i = 0; arr_i < n; arr_i++) {
        scanf("%d", &arr[arr_i]);
        ret += arr[arr_i];
    }
    printf("%d\n", ret);
    return 0;
}
