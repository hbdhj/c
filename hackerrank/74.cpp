/*
Copyright 2017 <Deng Haijun>

Dashboard > Tutorials > Cracking the Coding Interview > Sorting: Bubble Sort 

Sample Input 0

3
1 2 3

Sample Output 0

Array is sorted in 0 swaps.
First Element: 1
Last Element: 3

*/

#include "./common.h"

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
       cin >> a[a_i];
    }
    int total_swap = 0;
    for (int i = 0; i < n; i++) {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        } else  {
            total_swap += numberOfSwaps;
        }
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d\n",
           total_swap, a[0], a[n-1]);
    return 0;
}
