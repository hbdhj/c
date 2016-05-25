class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        }
        int max_len = 0;
        vector<int> dp(len, 0);

        for(int i = 0; i < len; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && (dp[j] + 1) > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }
};
