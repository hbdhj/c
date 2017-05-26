#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i=0; i<nums.size()-1; i+=2)
        {
            ret += nums[i];
        }
        return ret;
    }
};

int main()
{
    int myints[] = {1,2,3,4};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    Solution s;
    cout<<"result = "<<s.arrayPairSum(v1)<<endl;
    return 0;
}
