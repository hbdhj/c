#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int ret = 0;
        int bit=0;
        while(num)
        {
            if ((num&1)==0)
                ret+=1<<bit;
            bit++;
            num = num>>1;
            cout<<"bit = "<<bit<<", num = "<<num<<", ret = "<<ret<<endl;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    std::cout<<s.findComplement(1)<<std::endl;
    std::cout<<s.findComplement(5)<<std::endl;
    return 0;
}
