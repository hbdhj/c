#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ret="";
        for (int i=0; i<numRows; i++) {
            for (int j=i; j<s.length(); j+=(numRows+1)) {
                if (i==(numRows-1)/2) {
                    ret+=s[j];
                    int m;
                    if (numRows%2)
                        m = j+(numRows+1)/2;
                    else
                        m = j+numRows/2+1;
                    cout<<"i = "<<i<<", j = "<<j<<", m = "<<m<<endl;
                    if (m<s.length())
                        ret+=s[m];
                } else {
                    ret+=s[j];
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.convert("PAYPALISHIRING", 3)<<endl;
    cout<<s.convert("ABC", 2)<<endl;
    cout<<s.convert("AB", 2)<<endl;
    return 0;
}
