/*
Utopian Tree

Sample Input

3
0
1
4

Sample Output

1
2
7

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, y;
    cin>>a>>b>>n;
    vector<unsigned long long> h(61);
    h[0] = 1;
    h[1] = 2;
	for(int i=2; i<61; i++)
		h[i]=h[i-1]*2+1;
    for(int i=0; i<t; i++) {
		cin>>y;
        cout<<h[y];
	}
    return 0;
}
