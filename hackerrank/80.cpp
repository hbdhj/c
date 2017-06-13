/*
Copyright 2017 <Deng Haijun>

All Competitions > Week of Code 33 > Pattern Count

Sample Input 0

3
100001abc101
1001ab010abc01001
1001010001

Sample Output 0

2
2
3

*/

#include "./common.h"

int patternCount(string s) {
    // Complete this function
    int ret = 0;
    int status = 0;  // 0 - to search, 1 - got 1, 2 - got 0
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '1':
                if (status == 0)
                    status = 1;
                if (status == 2) {
                    status = 1;
                    ret++;
                }
                break;
            case '0':
                if (status == 1)
                    status = 2;
                break;
            default:
                status = 0;
                break;
        }
    }
    return ret;
}

int main() {
    int q;
    cin >> q;
    for (int a0 = 0; a0 < q; a0++) {
        string s;
        cin >> s;
        int result = patternCount(s);
        cout << result << endl;
    }

    return 0;
}