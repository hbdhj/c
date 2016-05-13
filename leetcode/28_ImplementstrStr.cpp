#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        cout<<haystack<<", "<<needle<<endl;
        if (needle.length()==0)
            return 0;
        if (haystack.length()==0)
            return -1;
        if (needle.length()>haystack.length())
            return -1;
        for (int h = 0; h < haystack.length()-needle.length()+1; h++) {
            bool match = true;
            for (int n = 0; n < needle.length(); n++) {
                if ( haystack[h+n] != needle[n] ) {
                    match = false;
                    break;
                }
            }
            if (match)
                return h;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("b", "b")<<endl;
    cout<<s.strStr("abc", "b")<<endl;
    cout<<s.strStr("mississippi", "mississippi")<<endl;
}
