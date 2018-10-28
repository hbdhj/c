#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int repeats = 0;
    for (int i = 0; i<s.length(); i++) {
        if (s[i] == 'a')
            repeats ++;
    }
    long ret = repeats * (n / s.length());
    for (int i = 0; i<(n % s.length()) ; i++)
        if (s[i] == 'a')
            ret ++;
    return ret;
}

int main()
{
    cout << repeatedString("aba", 10) <<endl;
    cout << repeatedString("a", 100) <<endl;
    cout << repeatedString("aa", 4) <<endl;
    cout << repeatedString("aab", 11) <<endl;

    return 0;
}
