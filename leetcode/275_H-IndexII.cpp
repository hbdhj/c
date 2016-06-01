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
            //sort(citations.begin(), citations.end());
            //printVector(citations);
            int end=len-1;
            int start=0;
            int pivot=start+(end-start)/2;
            while(start<end) {
                if ((citations[pivot]<len-pivot)&&(citations[pivot+1]>=len-pivot+1)) {
                    break;
                }
                if (citations[pivot]<len-pivot)
                    start = pivot+1;
                else
                    end = pivot-1;
                pivot=start+(end-start)/2;
            }
            return len-pivot-1;
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
