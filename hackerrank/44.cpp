/*
Copyright 2017 <Deng Haijun>

Security > Functions Security > Bijective Functions

Sample Input

3
1 2 3

Sample Output

YES

*/

#include "./common.h"

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    set<int> x;
    set<int>::iterator it;
    bool uniq = true;
    cin >> n;
    while (n--) {
        cin >> k;
        it = x.find(k);
        if (it == x.end())
            x.insert(it, k);
        else
            uniq = false;
    }
    if (uniq)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
