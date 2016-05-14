#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int count(int n) {
        int ret = 0;
        while(n) {
            ret += (n%10)*(n%10);
            n=n/10;
        }
        //cout<<ret<<endl;
        return ret;
    }
    bool isHappy(int n) {
        vector<int> v;
        int cnt = count(n);
        while(find(v.begin(), v.end(), cnt)==v.end()) {
            v.push_back(cnt);
            cnt = count(cnt);
            if (cnt==1)
                break;
        }
        if (cnt==1)
            return true;
        return false;
    }
};

int main() {
    Solution s;
    cout<<s.isHappy(19)<<endl;
    cout<<s.isHappy(68)<<endl;
    return 0;
}
