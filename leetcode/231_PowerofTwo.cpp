#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<1)
            return false;
        if (n<3)
            return true;
        while (n) {
            if (n&1) {
                n=n>>1;
                break;
            }
            else
                n=n>>1;
        }
        if(n)
            return false;
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isPowerOfTwo(4)<<endl;
    cout<<s.isPowerOfTwo(6)<<endl;
    cout<<s.isPowerOfTwo(8)<<endl;
}
