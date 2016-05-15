#include "common.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        cout<<"getHint("<<secret<<", "<<guess<<") return ";
        vector<int> scrt[10];
        vector<int> gs[10];
        for (int i=0; i<secret.length(); i++) {
            scrt[secret[i]-'0'].push_back(i);
            gs[guess[i]-'0'].push_back(i);
        }

        int bull = 0;
        int cow = 0;
        for (int i=0; i<10; i++) {
            if ((scrt[i].size())&&(gs[i].size())) {
                int scrt_i = 0;
                int gs_i = 0;
                int tmp_bull = 0;
                while ((scrt_i<scrt[i].size())&&(gs_i<gs[i].size())) {
                    if (scrt[i][scrt_i]<gs[i][gs_i]) {
                        //cow++;
                        scrt_i++;
                    } else if (scrt[i][scrt_i]>gs[i][gs_i]) {
                        //cow++;
                        gs_i++;
                    } else {
                        tmp_bull++;
                        scrt_i++;
                        gs_i++;
                    }
                }
                bull+=tmp_bull;
                cow += min(gs[i].size(), scrt[i].size())-tmp_bull;
            }
        }
        ostringstream oss;
        oss << bull <<"A"<<cow<<"B";
        return oss.str();
    }
};

int main() {
    Solution s;
    cout<<s.getHint("1807", "7810")<<endl;
    cout<<s.getHint("1123", "0111")<<endl;
    cout<<s.getHint("11", "01")<<endl;
    cout<<s.getHint("011", "011")<<endl;
    return 0;
}
