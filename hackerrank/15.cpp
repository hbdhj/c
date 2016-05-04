/*

Sherlock and Array

Sample Input

2
3
1 2 3
4
1 2 3 3

Sample Output

NO
YES

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n;
    cin>>t;
    
    for(int i=0; i<t; i++) {
        cin>>n;
        vector<int> a(n);
		int s = 0;
		for(int a_i=0; a_i<n; a_i++) {
			cin>>a[a_i];
			s += a[a_i];
		}
		int l_s = 0;
		int r_s = s-a[0];
		bool found = false;
		for(int a_i=0; a_i<n; a_i++) {
			lc += a[i-1];
			rc -= a[i];
			if (l_s==r_s) {
				found = true;
				break;
			}
		}
		if(found)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
    return 0;
}
