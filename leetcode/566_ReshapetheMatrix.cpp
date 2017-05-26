#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        vector<vector<int> > ret;
        for (int i=0; i<r; i++)
        {
            vector<int> row(c);
            ret.push_back(row);
        }
        int cur_r = nums.size();
        int cur_c = nums[0].size();
        for(int i = 0; i<r*c; i++)
        {
            if (i<cur_r*cur_c)
                ret[i/c][i%c] = nums[i/cur_c][i%cur_c];
            else
                ret[i/c][i%c] = 0;
        }

        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                cout<<ret[i][j]<<" ";
            }
            cout<<endl;
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > input;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(2);
    input.push_back(row1);
    vector<int> row2;
    row2.push_back(3);
    row2.push_back(4);
    input.push_back(row2);

    vector<vector<int> > ret = s.matrixReshape(input, 1, 4);
    return 0;
}
