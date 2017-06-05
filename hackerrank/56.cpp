/*

Copyright 2017 <Deng Haijun>

Mathematics > Fundamentals > Leonardo's Prime Factors 

Sample Input

6
1
2
3
500
5000
10000000000

Sample Output

0
1
1
4
5
10

*/

/* you only have to complete the function given below.  
Node is defined as  
*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    int q;
    int64 n;
    int myints[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
                    59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
                    113, 127, 131, 137, 139, 149};
    vector<int> primes (myints, myints + sizeof(myints) / sizeof(int) );
    cin >> q;

    while (q--) {
        cin >> n;
        int i = 0;
        if (n >= 614889782588491410) {
            cout << 15 << endl;
        } else {
            int64 total = primes[i];
            while (n >= total) {
                i++;
                if (i < primes.size())
                    total = total * primes[i];
                else
                    break;
                }
                cout << i << endl;
        }
    }
    return 0;
}
