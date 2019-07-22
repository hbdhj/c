#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    vector<int> level(s.size() + 1, 0);
    for (int i = 0; i<s.length(); i++) {
        if (s[i] == 'U')
            level[i+1] = level[i]+1;
        else if (s[i] == 'D')
            level[i+1] = level[i]-1;
    }
    int ret = 0;
    for (int i = 1; i<level.size(); i++) {
        if ((level[i-1]==0) && (level[i]==-1))
            ret ++;
    }
    return ret;
}

int main()
{
    string s = "DDUUDDUDUUUD";
    cout << countingValleys(s.size(), s) <<endl;

    return 0;
}
