/*

Copyright 2017 <Deng Haijun>

Dashboard Algorithms Game Theory Tower Breakers 

Sample Input

2
2 2
1 4

Sample Output

2
1

*/
unsigned int gcd(unsigned int a,unsigned int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << (m == 1 || n % 2 == 0 ? 2 : 1) << endl;
    }
    return 0;
}
