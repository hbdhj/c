#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string rev_a = reverse(a);
        string rev_b = reverse(b);
        string ret = addReverseBinary(rev_a, rev_b);
        return reverse(ret);
    }

    string addReverseBinary(string a, string b) {
        string longStr = a.length()>b.length()?a:b;
        string shortStr = a.length()>b.length()?b:a;
        string ret = a.length()>b.length()?a
    }

    string reverse(string a) {
        string ret = a;
        int len = a.length();
        for (int i = 0; i<len; i++) {
            ret[i]=a[len-i-1];
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout<<s.addBinary("11", "1")<<endl;
    return 0;
}
