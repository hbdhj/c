#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        int i = 32;
        while(i--) {
            ret=(ret<<1)+(n&1);
            n=n>>1;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.reverseBits(43261596)<<endl;
}
