/*

Copyright 2017 <Deng Haijun>

Data Structures > Stacks > Maximum Element 

Sample Input

10
1 97
2
1 20
2
1 26
1 20
2
3
1 91
3

Sample Output

26
91

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::list;
using std::endl;
using std::cout;
using std::max_element;
int main() {
    int n, t, x;
    cin >> n;
    list<int> s;
    for (int i = 0; i < n; i++) {
        cin >> t;
        switch(t) {
            case 1:
				s.push_back(x);
                break;
            case 2:
				s.pop_back();
                break;
            case 3:
				cout<<*max_element(s.begin(), s.end());
                break;
            default:
                break;
       }
    }

    return 0;
}
