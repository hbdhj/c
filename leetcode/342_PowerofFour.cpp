#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num<1)
            return false;
        int count=0;
        while((num&1)==0) {
            num=(num>>1);
            count++;
        }
        if((num==1)&&((count%2)==0))
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.isPowerOfFour(4)<<endl;
    cout<<s.isPowerOfFour(16)<<endl;
    cout<<s.isPowerOfFour(1)<<endl;
    cout<<s.isPowerOfFour(8)<<endl;
    cout<<s.isPowerOfFour(12)<<endl;
}
