#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        cout<<"str = "<<str<<endl;
        if (str.length()==0)
            return 0;
        int start = 0;
        while(str[start]==' ')
            start++;
        int end = str.length();
        while(str[end-1]==' ')
            end--;
        if ((str.length()==1) && (str[start]>'9' || str[start]<'0'))
            return 0;
        if ((str.length()>1) && (str[start]>'9' || str[start]<'0') && (str[start]!='+' && str[start]!='-'))
            return 0;
        int i = start;
        if (str[start]=='-' || str[start]=='+')
            i++;
        long ret = 0;
        for(; i<end; i++)
        {
            if (str[i]<='9' && str[i]>='0')
                ret=ret*10+str[i]-'0';
            else
                break;
            if (ret>0xFFFFFFFF) {
                ret=0xFFFFFFFF;
                break;
            }
        }
        if (str[start]=='-')
            ret=0-ret;
        cout<<"line 32 ret = "<<ret<<endl;
        if (ret>0x7FFFFFFF)
            ret=0x7FFFFFFF;
        cout<<"line 35 ret = "<<ret<<endl;
        if (ret<(-0x7FFFFFFF-1))
            ret=-0x7FFFFFFF-1;
        cout<<"line 38 ret = "<<ret<<endl;
        return ret;
    }
};

int main()
{
    Solution s;
    /*cout<<s.myAtoi("a12")<<endl;
    cout<<s.myAtoi("1")<<endl;
    cout<<s.myAtoi("+1")<<endl;
    cout<<s.myAtoi("-1")<<endl;
    cout<<s.myAtoi("-")<<endl;
    cout<<s.myAtoi("+")<<endl;
    cout<<s.myAtoi("123456789")<<endl;
    cout<<s.myAtoi("-123456789")<<endl;
    cout<<s.myAtoi("    -00134")<<endl;
    cout<<s.myAtoi("  -0012a42")<<endl;*/
    cout<<s.myAtoi("2147483648")<<endl;
    cout<<s.myAtoi("-2147483648")<<endl;
    cout<<s.myAtoi("    +11191657170")<<endl;
    cout<<s.myAtoi("-2147483649")<<endl;
    cout<<s.myAtoi("9223372036854775809")<<endl;
}
