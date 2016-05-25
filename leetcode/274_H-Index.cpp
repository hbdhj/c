#include "common.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len==0) {
            return 0;
        } else if (len==1) {
            if (citations[0])
                return 1;
            else
                return 0;
        } else {
            sort(citations.begin(), citations.end());
            //printVector(citations);
            int i=len-1;
            for(; i>=0; i--) {
                if (citations[i]<len-i)
                    break;
            }
            return len-i-1;
        }
    }
};

int main()
{
    Solution s;
    int myints[] = {3, 0, 6, 1, 5};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    printVector(v1);
    cout<<s.hIndex(v1)<<endl;
    return 0;
}
