class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counts;
        for (int i = 0; i < nums.size(); i++) {
            if (counts.find(nums[i])!=counts.end())
                counts[nums[i]]++;
            else
                counts[nums[i]] = 1;
        }
        int max_len = 0;
        for (map<int, int>::iterator it=counts.begin(); it!=counts.end(); ++it) {
            if (counts.find(it->first - 1)!=counts.end()) {
                if ((counts[it->first - 1] + it->second) > max_len)
                    max_len = counts[it->first - 1] + it->second;
            }
        }
        return max_len;
    }
};