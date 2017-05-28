#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i<=n; i++)
        {
            string s = "";
            if (i%3==0)
            {
                s+="Fizz";
            }
            if (i%5==0)
            {
                s+="Buzz";
            }
            if ((i%3)&&(i%5))
            {
                s=to_string(i);
            }
            ret.push_back(s);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> results = s.fizzBuzz(15);
    for(vector<string>::iterator it = results.begin(); it != results.end(); it++)
        cout<<*it<<endl;
    return 0;
}
