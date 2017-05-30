/*
Copyright 2017 <Deng Haijun>

Algorithms > Sorting > Big Sorting

Sample Input 0

6
31415926535897932384626433832795
1
3
10
3
5

Sample Output 0

1
3
3
5
10
31415926535897932384626433832795

*/

// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

bool string_comp(string a, string b) {
    bool ret;
    if (a.length() > b.length()) {
        ret = false;
    } else if (a.length() < b.length()) {
        ret = true;
    } else {
        ret = (a.compare(b) < 0);
    }
    /*if (ret)
        cout<<"'"<<a<<"' is greater than '"<<b<<"'"<<endl;
    else
        cout<<"'"<<a<<"' is less than or equal to '"<<b<<"'"<<endl;*/
    return ret;
}

void print_str(string str) {
    cout << str <<endl;;
}

int main() {
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for (int unsorted_i = 0; unsorted_i < n; unsorted_i++) {
       cin >> unsorted[unsorted_i];
    }
    // your code goes here
    sort(unsorted.begin(), unsorted.end(), string_comp);
    for_each(unsorted.begin(), unsorted.end(), print_str);
    return 0;
}
