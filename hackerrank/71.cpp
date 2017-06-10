/*

Copyright 2017 <Deng Haijun>

Dashboard > Mathematics > Fundamentals > Sherlock and Moving Tiles 

Sample Input

10 1 2
2
50
100

Sample Output

4.1421
0.0000


*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long l, s1, s2, q, qi;
    cin >> l >> s1 >> s2 >> q;
    while (q--) {
        cin >> qi;
        printf("%.10f\n", (double(l) - sqrt(double(qi)))*sqrt(2.0)/(s2>s1?(s2-s1):(s1-s2)));
    }
    return 0;
}