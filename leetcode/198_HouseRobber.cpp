#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int i1, int i2) {
        return i1>i2?i1:i2;
    };
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size<1)
            return 0;
        if (size<2)
            return nums[0];
        if (size<3)
            return max(nums[0], nums[1]);
        nums[1] = max(nums[0], nums[1]);
        for(int i =2; i< size; i++) {
            nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
        }
        for(int i =0; i< size; i++) {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        return nums[size-1];
    }
};

int main()
{
    Solution s;
    int myints[] = {2,1,1,2};
    vector<int> v4 (myints, myints + sizeof(myints) / sizeof(int) );
    cout<<s.rob(v4)<<endl;
    return 0;
}
