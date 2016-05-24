class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3)
            return false;
        else {
            int sz = nums.size();
            for(int i=0; i<sz-2; i++) {
                for (int j=i+1; j<sz-1; j++) {
                    if (nums[i]<nums[j]) {
                        for (int k=j+1; k<sz; k++) {
                            if(nums[j]<nums[k])
                                return true;
                        }
                    }
                }
            }
            return false;
        }
    }
};
