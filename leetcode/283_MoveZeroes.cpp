#include "common.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0;
        int p2 = p1+1;
        int sz = nums.size();
        while(p2<sz) {
            while((p1<sz)&&(nums[p1]!=0))
                p1++;
            p2 = p1+1;
            while((p2<sz)&&(nums[p2]==0))
                p2++;
            if((p2<sz)&&(p1<p2)&&(nums[p1]==0)&&(nums[p2]!=0)) {
                nums[p1]=nums[p2];
                nums[p2]=0;
                //p1=p2;
            }
            //printVector(nums);

        }
    }
};

int main()
{
    Solution s;
    int myints[] = {0,1,0,3,12};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    printVector(v1);
    s.moveZeroes(v1);
    printVector(v1);
    return 0;
}
