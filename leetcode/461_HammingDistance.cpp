#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xo = x ^ y;
        //std::cout<<xo<<std::endl;
        int ret = 0;
        while(xo)
        {
            ret += xo&1;
            //std::cout<<"xoret = "<<ret<<std::endl;
            xo = xo >> 1;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    std::cout<<s.hammingDistance(1, 4)<<std::endl;
    return 0;
}
