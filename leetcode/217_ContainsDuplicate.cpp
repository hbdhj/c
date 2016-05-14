class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size()==0)
            return false;
        sort(nums.begin(), nums.end());
        bool ret = false;
        for (int i = 0; i<nums.size()-1; i++) {
            if (nums[i]==nums[i+1]) {
                ret = true;
                break;
            }
        }
        return ret;
    }
};
