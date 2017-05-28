#include <map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    map<char,int> key_row_map;
    vector<string> findWords(vector<string>& words) {
        key_row_map['a']=2;
        key_row_map['b']=3;
        key_row_map['c']=3;
        key_row_map['d']=2;
        key_row_map['e']=1;
        key_row_map['f']=2;
        key_row_map['g']=2;
        key_row_map['h']=2;
        key_row_map['i']=1;
        key_row_map['j']=2;
        key_row_map['k']=2;
        key_row_map['l']=2;
        key_row_map['m']=3;
        key_row_map['n']=3;
        key_row_map['o']=1;
        key_row_map['p']=1;
        key_row_map['q']=1;
        key_row_map['r']=1;
        key_row_map['s']=2;
        key_row_map['t']=1;
        key_row_map['u']=1;
        key_row_map['v']=3;
        key_row_map['w']=1;
        key_row_map['x']=3;
        key_row_map['y']=1;
        key_row_map['z']=3;
        vector<string> results;
        for (vector<string>::iterator it = words.begin() ; it != words.end(); ++it)
        {
            cout<<*it<<endl;
            if (checkString(*it))
            {
                results.push_back(*it);
                cout<<"add "<<*it<<endl;
            }
            else
            {
                cout<<"can't add "<<*it<<endl;
            }
        }
        return results;
    }
    bool checkString(string& input) {
        int row = key_row_map[lower(input[0])];
        cout<<"row = "<<row<<endl;
        for(int i=1; i<input.length(); i++)
        {
            cout<<"new row = "<<key_row_map[lower(input[i])]<<endl;
            if(key_row_map[lower(input[i])]!=row)
                return false;
        }

        return true;
    }
    char lower(char c) {
        return (c>='A'&&c<='Z')?('a'+c-'A'):c;
    }
};

int main()
{
    vector<string> words;
    words.push_back("Hello");
    words.push_back("Alaska");
    words.push_back("Dad");
    words.push_back("Peace");
    Solution s;
    vector<string> ret = s.findWords(words);
    for (vector<string>::iterator it = ret.begin() ; it != ret.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
