/*

Copyright 2017 <Deng Haijun>

Tutorials > 10 Days of Statistics > Day 1: Quartiles

Sample Input

9
3 7 8 5 12 14 21 13 18

Sample Output

6
12
16

*/

#include "./common.h"

int main() {
    int n;
    cin >> n;
    vector<int> xis(n);
    for (int i = 0; i < n; i++) {
        cin >> xis[i];
    }
    if (n%2) {
        if ((n/2)%2)
			cout<<(xis[n/4]+xis[n/4+1])/2<<endl;
		else
			cout<<xis[n/4]<<endl;
		cout<<xis[n/2]<<endl;
		if ((n/2)%2)
			cout<<(xis[n/4+n/2]+xis[n/4+n/2+1])/2<<endl;
		else
			cout<<xis[n/4+n/2]<<endl;
	} else {
        if ((n/2)%2)
			cout<<xis[n/4]<<endl;
		else
			cout<<(xis[n/4-1)+xis(n/4)]/2<<endl;
	    cout<<(xis[n/2]+xis[n/2-1])/2<<endl;
    	if ((n/2)%2)
			cout<<xis[n/4+n/2]<<endl;
		else
			cout<<(xis[n/4+n/2-1]+xis[n/4+n/2])/2<<endl;
	}
    return 0;
}