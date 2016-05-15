#include "common.h"

class NumArray {
public:
    NumArray(vector<int> &nums) {
        res = nums;
        int sz = nums.size();
        for (int i=1; i<sz; i++) {
            res[i]+=res[i-1];
        }
    }

    int sumRange(int i, int j) {
        if (i==0)
            return res[j];
        return res[j]-res[i-1];
    }
private:
    vector<int> res;
};

int UnitTest1() {
    int myints[] = {-2, 0, 3, -5, 2, -1};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    NumArray s(v1);

    cout<<s.sumRange(0, 2)<<endl; // 1
    cout<<s.sumRange(2, 5)<<endl; // -1
    cout<<s.sumRange(0, 5)<<endl; // -3

    return 0;
}

int main() {
    UnitTest1();
    return 0;
}
