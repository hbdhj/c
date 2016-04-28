/*


Running Time of Algorithms


Sample Input

5
2 1 3 1 2

Sample Output

4


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

void insertionSort(vector <int>  ar) {
    int shift = 0;
    for(int chk_i = 1; chk_i<ar.size(); chk_i++) {
		int chk = ar[chk_i];
	    int cmp_i = chk_i;
	    while(((cmp_i--)>0)&&(ar[cmp_i]>chk)){
		    ar[cmp_i+1] = ar[cmp_i];
		}
	    if (chk_i!=(cmp_i+1))
		{
			ar[cmp_i+1]=chk;
			shift+=(chk_i-cmp_i-1);
        }		
	}
	cout<<shift<<endl;
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

    insertionSort(_ar);
    return 0;
}