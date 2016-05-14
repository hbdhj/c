/*
 * algo: backtrace, string
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.length()==0)
            return ret;
        vector<vector<char> > map;
        int num_btn[8] = {3,3,3,3, 3,4,3,4};
        int level = 0;
        int sum = 0;
        vector<char>  *pchar_lvl = NULL;
        for (int i = 0; i<26; i++) {
            if (pchar_lvl == NULL)
                pchar_lvl = new vector<char>(num_btn[level]);
            (*pchar_lvl)[i-sum]='a'+i;
            if (i-sum==num_btn[level]) {
                map.push_back(*pchar_lvl);
                pchar_lvl = NULL;
                sum+=num_btn[level];
                level++;
            }

        }
        if (digits.length()==1) {
            for (int i=0; i<map[digits[0]-'2'].size(); i++) {
                string ap = basic_string(map[digits[0]-'2'][i]);
                ret.append(ap);
            }
            return ret;
        }
        char lastChar = digits[digits.length()-1];
        int nums = sizeof(map[lastChar - '2']);
        digits.pop_back();
        vector<string> lessdigit = letterCombinations(digits);
        for (int i = 0; i < lessdigit.size(); i++) {
            for (int j = 0; j < nums; j++) {
                ret.push_back(lessdigit[i]+map[lastChar-'2'][j]);
            }
        }
        return ret;
    }
};

int printVector(vector<string> strings) {
    if (strings.size()>0) {
        for (int i=0; i<strings.size()-1; i++) {
            cout<<strings[i]<<", ";
        }
        cout<<strings[strings.size()-1]<<endl;
    }
    return 0;
}
int main()
{
    Solution s;
    vector<string> ret=s.letterCombinations("23");
    printVector(ret);

    return 0;
}
