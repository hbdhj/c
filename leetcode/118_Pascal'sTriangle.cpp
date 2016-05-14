class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows>0) {
            vector<int> first;
            first.push_back(1);
            ret.push_back(first);
        }
        if (numRows>1) {
            vector<int> second;
            second.push_back(1);
            second.push_back(1);
            ret.push_back(second);
        }
        for(int i=2; i < numRows; i++) {
            vector<int> row(i+1, 1);
            for (int j=1; j<i; j++) {
                row[j]=ret[i-1][j-1]+ret[i-1][j];
            }
            ret.push_back(row);
        }
        return ret;
    }
};
