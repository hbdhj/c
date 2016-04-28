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

void printVector(vector <int>  ar) {
    for(int arr_i = 0; arr_i < ar.size(); arr_i++){
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
			ar[l] = p;
		
		printVector(ar);
	}
}

int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
    
     for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

   quick_sort(_ar);
   
   return 0;
}