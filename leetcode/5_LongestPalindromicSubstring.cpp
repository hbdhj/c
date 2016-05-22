#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int pos1 = 0;
        int max1 = 0;
        int sz = s.length();
        if (sz==1)
            return s;
        if (sz==2) {
            if (s[0]==s[1]) {
                return s;
            } else {
                return "";
            }
        }
        int i, j;
        for ( i = 0; i<sz; i++) {
            //cout<<s[i]<<" ";
            int scope = min(i, sz-i-1);
            for ( j=1; j<=scope; j++) {
                if (s[i-j]!=s[i+j])
                    break;
            }
            if (max1<j) {
                max1 = j;
                pos1 = i;
            }
            //cout<<i<<", "<<j<<", "<<scope<<", "<<max1<<", "<<pos1<<endl;
        }
        int pos2 = 0;
        int max2 = 0;
        if (sz>1) {
            for ( i = 1; i<sz; i++) {
                if (s[i]==s[i-1]) {
                    int scope = min(i-1, sz-i-1);
                    for ( j=1; j<=scope; j++) {
                        if (s[i-j-1]!=s[i+j])
                            break;
                    }
                    if (max2<j) {
                        max2 = j;
                        pos2 = i;
                    }
                    //cout<<i<<", "<<scope<<", "<<max2<<", "<<pos2<<endl;
                }
            }
        }
        cout<<max1<<", "<<pos1<<", "<<max2<<", "<<pos2<<endl;
        if ((max1*2+1)>(max2*2+2))
            return s.substr(pos1-max1+1, max1*2-1);
        else
            return s.substr(pos2-max2, max2*2);
    }
};

int main() {
    Solution s;
    cout<<s.longestPalindrome("cabad")<<endl;;
    cout<<s.longestPalindrome("abb")<<endl;;
    return 0;
}
