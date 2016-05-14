#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ret=0;
        for (int i = 0; i<s.length(); i++) {
            ret=ret*26+(s[i]-'A')+1;
            cout<<ret<<endl;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout<<s.titleToNumber("A")<<endl;
    cout<<s.titleToNumber("AA")<<endl;
    return 0;
}
