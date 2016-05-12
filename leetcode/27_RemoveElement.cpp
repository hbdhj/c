#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()==0)
            return 0;
        int s = 0;
        int e = nums.size()-1;
        while(s<e) {
            cout<<"l13 "<<s<<", "<<e<<endl;
            while (nums[s]!=val && s<e)
                s++;
            cout<<"l16 "<<s<<", "<<e<<endl;
            while (nums[e]==val && s<e)
                e--;
            cout<<"l19 "<<s<<", "<<e<<endl;
            if (s<e) {
                nums[s] = nums[e];
                nums[e] = val;
                s++;
                e--;
            }
            cout<<"l26 "<<s<<", "<<e<<endl;
        }
        if (nums[s]!=val)
            return s+1;
        return s;
    }
};

int main()
{
    Solution s;
    int myints[] = {2,2,2};
    //int myints[] = {3,5};
    //int myints[] = {3,2,2,3};
    vector<int> a (myints, myints + sizeof(myints) / sizeof(int) );
    cout<<s.removeElement(a, 3)<<endl;
}
