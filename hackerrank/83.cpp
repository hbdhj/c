#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    vector<int> counts(100, 0);
    for (vector<int>::iterator it = ar.begin() ; it != ar.end(); ++it) {
        counts[(*it)-1] ++;
    }
    int ret = 0;
    for (vector<int>::iterator it = counts.begin() ; it != counts.end(); ++it) {
        ret += (*it)/2;
    }
    return ret;
}

int main()
{
    int myints[] = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    std::vector<int> ar (myints, myints + sizeof(myints) / sizeof(int) );
    cout << sockMerchant(ar.size(), ar) <<endl;

    return 0;
}
