/*
given an intergar array nums, return the number of range sums that lie in [low, upper] inclusive. Range sum s[i, j] is defined as the sume of the elems in nus between indices i and j (i<=j), inclusive.
Exmaple
Give nums = [-2, 5, -1], lower = -2, upper = 2,
Range S(0, 0) constains only the first element -2, its sum is also -2, inside [-2, 2], it is a valid range. Range S(0, 1) contains the first two elements -2 and 5, it sum is 3, exceeds the limit [-2, 2], it is not valid.

The three valid ranges for this array are S(0, 0), S(2, 2), S(0, 2), so at the last return 3.
Notes:
A brute force algorithm of O(n2) is not enougth, You should do better than that.
*/

int countRange(vector<int> nums, int low, int up) {
    for (int i = 1; i<nums.size(); i++) {
        nums[i]+=nums[i-1];
    }
    int count = 0;
    int start = 0;
    int end = 0;
    int sum = 0;
    while (end<nums.size()) {
        if (start==0)
            sum = nums[end];
        else
            sum = nums[end] - nums[start-1];
        if (sum<low)
            end++;
        else if (sum>up)
            start++;
        else {
            count++;
            end++;
        }
    }
    return count;
}
