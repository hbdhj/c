class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex==0) {
            vector<int> ret(1, 1);
            return ret;
        }
        if (rowIndex==1) {
            vector<int> ret(2, 1);
            return ret;
        }
        vector<int> up = getRow(rowIndex-1);
        vector<int> ret(rowIndex+1, 1);
        for (int i=1; i<rowIndex; i++)
            ret[i] = up[i-1]+up[i];
        return ret;
    }
};
