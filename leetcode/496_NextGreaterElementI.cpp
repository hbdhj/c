#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> pos;
        for (int i = 0; i < nums.size(); i++)
        {
            pos[nums[i]]=i;
        }
        vector<int> ret;
        for (vector<int>::iterator it1 = findNums.begin(); it1!=findNums.end(); it1++)
        {
            int find = -1;
            for (int i = pos[*it1]+1; i<nums.size(); i++)
            {
                if (nums[i]>(*it1))
                {
                    find = nums[i];
                    break;
                }
            }
            ret.push_back(find);
        }
        return ret;
    }
};

int main()
{
    int myints1[] = {4,1,2};
    vector<int> v1 (myints1, myints1 + sizeof(myints1) / sizeof(int) );
    int myints2[] = {1,3,4,2};
    vector<int> v2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
    Solution s;
    vector<int> ret = s.nextGreaterElement(v1, v2);
    for(int i = 0; i<ret.size(); i++)
    {
        cout<<ret[i]<<" ";
    }
    return 0;
}
