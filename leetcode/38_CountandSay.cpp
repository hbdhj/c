#include <iostream>
#include <stack>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string pre_calc[] = {"1", "11", "21", "1211", "111221"};
        if ((n<6)&&(n>0))
            return pre_calc[n-1];
        else {
            string former = countAndSay(n-1);
            char check = former[0];
            int count = 1;
            string ret = "";
            char buffer[10];
            for (int i=1; i<former.length(); i++) {
                if (former[i]!=check) {
                    snprintf(buffer, 10, "%d", count);
                    ret += buffer;
                    ret += check;
                    //cout<<"i = "<<i<<", check = "<<check<<", former["<<i<<"] = "<<former[i]<<", count = "<<count<<", ret = "<<ret<<endl;
                    check = former[i];
                    count=1;
                } else {
                    count++;
                }
            }
            snprintf(buffer, 10, "%d", count);
            ret += buffer;
            ret += check;
            return ret;
        }
    }
};

int main()
{
    Solution s;
    cout<<s.countAndSay(1)<<endl;
    cout<<s.countAndSay(2)<<endl;
    cout<<s.countAndSay(3)<<endl;
    cout<<s.countAndSay(4)<<endl;
    cout<<s.countAndSay(5)<<endl;
    cout<<s.countAndSay(6)<<endl;
    cout<<s.countAndSay(7)<<endl;
}
