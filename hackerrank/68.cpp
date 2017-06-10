/*

Copyright 2017 <Deng Haijun>

Dashboard > Tutorials > Cracking the Coding Interview > Strings: Making Anagrams 

Sample Input

10
1 97
2
1 20
2
1 26
1 20
2
3
1 91
3

Sample Output

26
91

*/

#include "./common.h"

int number_needed(string a, string b) {
    vector<int> a_c(26, 0);
    vector<int> b_c(26, 0);
    for (int a_i = 0; a_i < a.size(); a_i++) {
        a_c[a[a_i]-'a']++;
    }
    for (int b_i = 0; b_i < b.size(); b_i++) {
        b_c[b[b_i]-'a']++;
    }
    int ret = 0;
    for (int c_i = 0; c_i < 26; c_i++) {
        ret += (a_c[c_i] > b_c[c_i])?
               (a_c[c_i] - b_c[c_i]) : (b_c[c_i] - a_c[c_i]);
    }
    return ret;
}

int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}