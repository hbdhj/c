class Solution {
    public bool containsNearbyDuplicate(vector<int&gt;&amp; nums, int k)
    {
        unordered_map<int, int> mymap;
        int i = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it, ++i)
        {
            if (mymap.find(*it) != mymap.end()) {
                if (i - mymap[*it] <= k)
                    return true;
            }
            mymap[*it] = i;
        }
        return false;
    }
};
