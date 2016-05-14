class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return Helper(nums, 0, nums.size()-1);
    }
    int Helper(vector<int>& nums, int low, int high)
    {
        if(low == high)
            return low;
        int mid = low + (high-low)/2;
        if(nums[mid] > nums[mid+1])
            return Helper(nums, low, mid);
        else
            return Helper(nums, mid+1, high);
    }
};
