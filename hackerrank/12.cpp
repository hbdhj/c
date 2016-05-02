/*
Fibonacci Modified

Sample Input

0 1 5
Sample Output

5
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, n;
    cin>>a>>b>>n;
    vector<long long> f(n);
    f[0] = a;
    f[1] = b;
    for(int i=2; i<n; i++)
        f[i]=f[i-1]*f[i-1] + f[i-2];
    cout<<f[n-1]<<endl;
    return 0;
}
