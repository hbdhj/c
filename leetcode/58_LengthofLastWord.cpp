#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length()-1;
        while (((s[end]<'A') || (s[end]>'Z')) && ((s[end]<'a') || (s[end]>'z')))
            end--;
        int start = end;
        for (; start>=0; start--) {
            if (((s[start]<'A') || (s[start]>'Z')) && ((s[start]<'a') || (s[start]>'z')))
                break;
        }
        return end - start;
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLastWord("hello World")<<endl;
    cout<<s.lengthOfLastWord("a ")<<endl;
}
