/*

Copyright 2017 <Deng Haijun>

Insertion Sort - Part 2

Sample Input #1

6
1 4 3 5 6 2

Sample Output #1

1 4 3 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 2 3 4 5 6 

Sample Input #2

5
2 3 4 5 1

Sample Output #2

2 3 4 5 1
2 3 4 5 1
2 3 4 5 1
1 2 3 4 5

*/
#include "./common.h"

void printVector(vector <int>  ar) {
    for (int arr_i = 0; arr_i < ar.size(); arr_i++) {
        cout << ar[arr_i] << " ";
    }
    cout << endl;
}
void insertionSort(vector <int>  ar) {
    for (int chk_i = 1; chk_i < ar.size(); chk_i++) {
        int chk = ar[chk_i];
        bool brk = false;
        int cmp_i = chk_i;
        while (((cmp_i--) > 0)&&(ar[cmp_i] > chk)) {
            ar[cmp_i+1] = ar[cmp_i];
        }
        if (ar[cmp_i] > chk)
            ar[cmp_i] = chk;
        else
            ar[cmp_i+1] = chk;
        printVector(ar);
    }
}

int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for (int _ar_i=0; _ar_i < _ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    insertionSort(_ar);
    return 0;
}