class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        int pow5 = 5;
        while(n>=pow5) {
            ret+=n/pow5;
            if (pow5<=(0x7FFFFFFF/5))
                pow5*=5;
            else
                break;
        }
        return ret;
    }
};
