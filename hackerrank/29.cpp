/*

Lonely Integer

Sample Input:1

1
1

Sample Output:1

1

Sample Input:2

3
1 1 2

Sample Output:2

2

Sample Input:3

5
0 0 1 2 1

Sample Output:3

2

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
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int lonelyinteger(vector < int > a) {
	int ret = 0;
	for(int _a_i=0; _a_i<a.size(); _a_i++) 
		ret ^= a[_a_i];
	return ret;
}
int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}