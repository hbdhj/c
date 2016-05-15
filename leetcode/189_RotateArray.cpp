#include "common.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        // this method will TLE
        int size = nums.size();
        for (int i=0; i<k; i++) {
            int last = nums[size-1];
            for (int j=size-1; j>0; j--)
                nums[j]=nums[j-1];
            nums[0]=last;
            printVector(nums);
        }
        */
        int size = nums.size();
        int nowIndex = 0;
        int tmp1, tmp2 = nums[0];
        for(int j=0, i=0; j<size; j++){
            // store the value to move
            tmp1 = tmp2;
            // find the next position to set
            nowIndex = (k + nowIndex) % size;
            // get the current value of the next position
            tmp2 = nums[nowIndex];
            // set the value of the next poistion
            nums[nowIndex] = tmp1;
            // to avoid fall in a loop if size/k==0
            if(nowIndex == i) {
                nowIndex = ++i;
                tmp2 = nums[nowIndex];
            }
            cout<<"i = "<<i<<", j = "<<j<<", nowIndex = "<<nowIndex<<endl;
            printVector(nums);
        }
    }
};

int UnitTest1() {
    int myints[] = {1,2,3,4,5,6,7};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    Solution s;
    s.rotate(v1, 3);
    return 0;
}

int UnitTest2() {
    int myints[] = {1,2,3,4,5,6};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    Solution s;
    s.rotate(v1, 2);
    return 0;
}

int main() {
    //UnitTest1();
    UnitTest2();
    return 0;
}
