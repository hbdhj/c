/*

Copyright 2017 <Deng Haijun>

Algorithms > Search > Ice Cream Parlor


Sample Input

2
4
5
1 4 5 3 2
4
4
2 2 4 3

Sample Output

1 4
1 2

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::vector;
using std::endl;
using std::cout;
using std::sort;
using std::min;
using std::max;

class IceCream {
 public:
    int flavor;
    int index;

IceCream(int f, int i) {
    flavor = f;
    index = i;
}
};

bool compare(IceCream a, IceCream b) {
    return a.flavor < b.flavor;
}

int binarySearch(int first, int last, vector<IceCream> arr, int search) {
    if ( last < first )
        return -1;
    if (arr[(first + last)/2].flavor > search) {
        return binarySearch(first,  (first + last)/2 - 1, arr, search);
    } else if (arr[(first + last)/2].flavor < search) {
        return binarySearch((first + last)/2 + 1,  last, arr, search);
    } else {
        return arr[(first + last)/2].index;
    }
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for (int test = 0; test < t; test++) {
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        int firstIndex = 100000, secondIndex = 100000;
        for (int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if (search >= arr[i].flavor) {
                int index = binarySearch(i + 1, n - 1, arr, search);
                if ( index != -1 ) {
                    cout << min(arr[i].index, index) << " "
                         << max(arr[i].index, index) << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
