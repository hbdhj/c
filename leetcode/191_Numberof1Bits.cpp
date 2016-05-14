#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret=0;
        while(n) {
            ret+=(n&1);
            n=n>>1;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseBits(11)<<endl;
}
