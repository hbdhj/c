#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        cout<<s<<", "<<t<<endl;
        map<char, vector<int> > s_map;
        for (int i = 0; i<s.length(); i++){
            s_map[s[i]].push_back(i);
        }
        map<char, vector<int> > t_map;
        for (int i = 0; i<t.length(); i++){
            t_map[t[i]].push_back(i);
        }
        for (map<char,vector<int> >::iterator it=s_map.begin(); it!=s_map.end(); ++it) {
            if (it->second.size()!=t_map[t[it->second[0]]].size()) {
                return false;
            }
            if (it->second.size()>1) {
                for (int i=1; i<it->second.size(); i++) {
                    if (t[it->second[i]]!=t[it->second[0]])
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isIsomorphic("egg", "add")<<endl;
    cout<<s.isIsomorphic("foo", "bar")<<endl;
    cout<<s.isIsomorphic("paper", "title")<<endl;
    cout<<s.isIsomorphic("aa", "ab")<<endl;
    return 0;
}
