/*

Copyright 2017 <Deng Haijun>

Lower Bound-STL

Sample Input

 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15
Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8

*/

#include "./common.h"

int main() {
    int n, y, q;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> y;
        vector<int>::iterator low = std::lower_bound(x.begin(), x.end(), y);
        if ((*low) == y)
            cout << "Yes " << (low-x.begin()+1) << endl;
        else
            cout << "No " << (low-x.begin()+1) << endl;
    }

    return 0;
}
