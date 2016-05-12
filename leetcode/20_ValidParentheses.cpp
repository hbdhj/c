#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length()%2!=0)
            return false;
        if (s.length()==0)
            return true;
        stack<char> syb;
        for (int i = 0; i<s.length(); i++) {
            if (s[i]=='(' or s[i]=='[')
                syb.push(s[i]);
            if (s[i]==')')
                if (syb.size()==0 || syb.top()!='(')
                    return false;
                else
                    syb.pop();
            if (s[i]==']')
                if (syb.size()==0 || syb.top()!='[' )
                    return false;
                else
                    syb.pop();
        }
        if (syb.size()==0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    cout<<s.isValid("()")<<endl;
    cout<<s.isValid("()()")<<endl;
    cout<<s.isValid("(())")<<endl;
    cout<<s.isValid("([])")<<endl;
    cout<<s.isValid("([)]")<<endl;
}
