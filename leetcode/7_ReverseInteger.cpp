//#include <stdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long nx = x;
        if (x<0)
            nx=-x;
        long ret = 0;
        while(nx>0)
        {
            if (long(ret*10)>(0x7FFFFFFF-(nx%10)))
            {
                ret = 0;
                break;
            }
            ret=ret*10+nx%10;
            nx=nx/10;
        }
        if (x<0)
            return 0-ret;
        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.reverse(1563847412)<<endl;
}
