#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main()
{
    Solution s;
    int myints[] = {8,9,9,9,9,9,9,9};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    cout<<s.majorityElement(v1)<<endl;
    return 0;
}
