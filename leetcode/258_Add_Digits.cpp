class Solution {
public:
    int sumDigits(int num) {
        int ret = 0;
        while(num) {
            ret+=num%10;
            num/=10;
        }
        return ret;
    }
    int addDigits(int num) {
        int ret = sumDigits(num);
        while(ret>9) {
            ret = sumDigits(ret);
        }
        return ret;
    }
};
