#include <iostream>
#include <stack>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n==0)
            return "10";
        stack<pair<int, int> > num_stack;
        int c=n%10;
        while(n) {
            if (num_stack.empty()) {
                num_stack.push(pair<int, int>(n%10, 1));
            } else {
                if (n%10==num_stack.top().first) {
                    num_stack.top().second++;
                } else {
                    num_stack.push_back(pair<int, int>(n%10, 1));
                }    
            }
            n = n/10;
        }
        string ret = "";
        char buffer[10];
        while(num_stack.empty()==false) {
            itoa(num_stack.top().second, buffer, 10);
            ret+=buffer;
            itoa(num_stack.top().first, buffer, 10);
            ret+=buffer;
            num_stack.pop();
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout<<s.countAndSay(111221)<<endl;
}
