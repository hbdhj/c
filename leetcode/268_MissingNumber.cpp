class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if( nums.size() == 0) {
            return 0;
        }
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
