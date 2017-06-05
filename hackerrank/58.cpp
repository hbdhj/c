/*

Copyright 2017 <Deng Haijun>

Tutorials > Cracking the Coding Interview > Arrays: Left Rotation 

Sample Input

5 4
1 2 3 4 5

Sample Output

5 1 2 3 4

*/

#include <vector>
#include <iostream>


using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    vector<int> ret(n);
	for(int i=0; i<n; i++) {
		if (i+k<n)
			ret[i]=a[i+k];
		else
			ret[i]=a[i+k-n];
	}
	return ret;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}