/*

Copyright 2017 <Deng Haijun>

Tutorials > 10 Days of Statistics > Day 0: Weighted Mean

Sample Input

5
10 40 30 50 20
1 2 3 4 5

Sample Output

32.0

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
			cout<<(xis(n/4)+xis(n/4+1))/2<<endl;
		else
			cout<<xis(n/4)<<endl;
		cout<<xis(n/2)<<endl;
		if ((n/2)%2)
			cout<<(xis(n/4+n/2)+xis(n/4+n/2+1))/2<<endl;
		else
			cout<<xis(n/4+n/2)<<endl;
	} else {
        if ((n/2)%2)
			cout<<xis(n/4)<<endl;
		else
			cout<<(xis(n/4-1)+xis(n/4))/2<<endl;
	    cout<<(xis(n/2)+xis(n/2-1))/2<<endl;
    	if ((n/2)%2)
			cout<<xis(n/4+n/2)<<endl;
		else
			cout<<(xis(n/4+n/2-1)+xis(n/4+n/2))/2<<endl;
	}
    return 0;
}