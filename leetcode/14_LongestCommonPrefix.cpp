#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(string& str1, string& str2) {
        string ret = "";
        if ((str1.length()==0) || (str2.length()==0))
            return ret;
        int len = str1.length() < str2.length() ? str1.length() : str2.length();
        for (int i = 0; i<len; i++)
        {
            if (str1[i] != str2[i])
                break;
            ret += str1[i];
        }
        return ret;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
            return "";
        if (strs.size()==1)
            return strs[0];
        string ret = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            ret = longestCommonPrefix(ret, strs[i]);
            if (ret.length()==0)
                break;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> a;
    a.push_back("abc");
    a.push_back("def");
    cout<<s.longestCommonPrefix(a)<<endl;
}
