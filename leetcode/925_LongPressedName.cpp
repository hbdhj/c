#include "common.h"

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<char> c1, c2;
        vector<int> n1, n1;
        char c = name[0];
        c1.push(c);
        n1.push(1);
        for (size_t i=0; i<name.length(); i++) {
            if (name[i]==c) {
            } else {
            }
        }     
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.isLongPressedName("alex", "aaleex")<<endl;
    cout<<s.isLongPressedName("saeed", "ssaaedd")<<endl;
    cout<<s.isLongPressedName("leelee", "lleeelee")<<endl;
    cout<<s.isLongPressedName("laiden", "laiden")<<endl;
    return 0;
}
