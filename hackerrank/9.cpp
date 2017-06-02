/*

Quicksort 1 - Partition

Sample Input

5
4 5 3 7 2

Sample Output

3 2 4 5 7

*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void printVector(int*  ar, int start, int end) {
    for(int arr_i = start; arr_i < end; arr_i++){
        cout<<ar[arr_i]<<" ";
    }
    cout<<endl;
}

void quick_sort(int*  ar, int ll, int rr) {
    if (ll < rr)  
    {
        int l=ll;
        int r=rr;
        int p=ar[ll];
        while(l<r)
        {
            while(l<r&&ar[r]>=p)
                r--;
            if(l < r)
                ar[l++] = ar[r];
            while(l<r&&ar[l]<=p)
                l++;
            if(l < r)
                ar[r--] = ar[l];
        }
        ar[l] = p;
        
        printVector(ar, ll, rr);

        quick_sort(ar, ll, l - 1);
        quick_sort(ar, l + 1, rr);
    }
}

int main(void) {
    int _ar_size;
    cin >> _ar_size;
    int  _ar[_ar_size];

    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
    }

    quick_sort(_ar, 0, _ar_size-1);
   
    return 0;
}
