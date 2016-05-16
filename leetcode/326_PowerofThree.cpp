class Solution {
public:
    bool isPowerOfThree(int n) {
        int ret = n;
        while (ret>2) {
            if (ret%3==0)
                ret/=3;
            else
                return false;
        }
        return ret==1;
    }
};
