class Solution {
public:
    int singleNumber(vector<int>& nums) {
                int ret = 0;
        int mask = 1;
        while(mask)
        {
            int countOne = 0;   //number of digit 1
            for(int i = 0; i < nums.size(); i ++)
            {
                if(nums[i] & mask)
                    countOne ++;
            }
            if(countOne % 3 == 1)
                ret |= mask;
            mask <<= 1;
        }
        return ret;
    }
};
