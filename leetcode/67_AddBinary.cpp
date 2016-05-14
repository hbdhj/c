#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int shrtLen, lngLen;
        string shrtStr, lngStr, ret;
        if (b.length()>a.length()) {
            shrt = a.length();
            lngLen = b.length();
            shrtStr = a;
            lngStr = b;
        } else if (b.length()<=a.length()) {
            shrt = b.length();
            lngLen = a.length();
            shrtStr = b;
            lngStr = a;
        }
        for (int i=shrt-1; i>=0; i--) {
            lngStr[] = shrtStr[i] + lngStr[]
        }
    }
};

int main() {
    Solution s;
    cout<<s.addBinary("11", "1")<<endl;
    return 0;
}
