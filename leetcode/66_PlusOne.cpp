#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool allNine = true;
        for (int i=0; i<digits.size(); i++) {
            if (digits[i]!=9) {
                allNine = false;
                break;
            }
        }
        if (allNine) {
            vector<int> ret(digits.size()+1, 0);
            ret[0] = 1;
            return ret;
        } else {
            vector<int> ret(digits.size(), 0);
            for (int i=digits.size()-1; i>=0; i--) {
                ret[i]+=digits[i];
                if (i==digits.size()-1)
                    ret[i]++;
                if (ret[i]>9) {
                    ret[i-1]++;
                    ret[i]-=10;
                }
            }
            return ret;
        }
    }
};

int printVector(vector<int>& digits) {
    for (int i=0; i<digits.size(); i++) {
        cout<<digits[i];
    }
    cout<<endl;
    return 0;
};

int main()
{
    Solution s;
    /*vector<int> v1(1);
    v1[0] = 0;
    vector<int> r1 = s.plusOne(v1);
    printVector(r1);
    vector<int> v2(1);
    v2[0] = 1;
    vector<int> r2 = s.plusOne(v2);
    printVector(r2);
    vector<int> v3(1);
    v3[0] = 9;
    vector<int> r3 = s.plusOne(v3);
    printVector(r3);*/
    int myints[] = {8,9,9,9,9,9,9,9};
    vector<int> v4 (myints, myints + sizeof(myints) / sizeof(int) );
    vector<int> r4 = s.plusOne(v4);
    printVector(v4);
    printVector(r4);
    return 0;
}
