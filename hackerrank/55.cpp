/*

Copyright 2017 <Deng Haijun>

Mathematics > Fundamentals > Find the Point

Sample Input

2
0 0 1 1
1 1 2 2

Sample Output

2 2
3 3


*/

#include <iostream>

using std::out;
using std::endl;

int main() {
	int n, px, py, qx, qy;
	cin>>n;
	while(n--) {
		cin >> px >> py >> qx >> qy;
		cout << qx * 2 - px << " " << qy * 2 - py <<endl; 
	}
	return 0;
}