#include "common.h"

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //cout<<"======================"<<endl;
        vector<char> c_p;
        for (int i=0; i<pattern.length(); i++)
            c_p.push_back(pattern[i]);
        vector<string> str_p;
        size_t pos = str.find(' ');
        while(pos!=string::npos) {
            string word = str.substr (0, pos);
            str_p.push_back(word);
            str = str.substr (pos+1);
            pos = str.find(' ');
            //cout<<"word = "<<word<<", remained string = "<<str<<", pos = "<<pos<<endl;
        }
        str_p.push_back(str);

        if (c_p.size()!=str_p.size())
            return false;
        if (c_p.size()==0)
            return true;
        //cout<<c_p.size()<<", "<<str_p.size()<<endl;
        map<char, vector<int> > ch_pos_map;
        for (int i = 0; i<c_p.size(); i++) {
            //cout<<c_p[i]<<endl;
            map<char, vector<int> >::iterator it = ch_pos_map.find(c_p[i]);
            if(it == ch_pos_map.end()) {
                ch_pos_map[c_p[i]]=vector<int>();
            }
            ch_pos_map[c_p[i]].push_back(i);
        }
        /*
        for (map<char, vector<int> >::iterator map_it = ch_pos_map.begin(); map_it != ch_pos_map.end(); map_it++) {
            cout<<map_it->first<<":"<<endl;
            printVector(map_it->second);
        }
        */
        map<string, vector<int> > str_pos_map;
        for (int i = 0; i<str_p.size(); i++) {
            //cout<<str_p[i]<<endl;
            map<string, vector<int> >::iterator it = str_pos_map.find(str_p[i]);
            if(it == str_pos_map.end()) {
                str_pos_map[str_p[i]]=vector<int>();
            }
            str_pos_map[str_p[i]].push_back(i);
        }
        /*
        for (map<string, vector<int> >::iterator map_it = str_pos_map.begin(); map_it != str_pos_map.end(); map_it++) {
            cout<<map_it->first<<":"<<endl;
            printVector(map_it->second);
        }*/
        for (int i = 0; i<c_p.size(); i++) {
            vector<int> c_p_v = ch_pos_map[c_p[i]];
            vector<int> str_p_v = str_pos_map[str_p[i]];
            if (c_p_v.size()!=str_p_v.size())
                return false;
            for (int j=0; j<c_p_v.size(); j++) {
                if (c_p_v[j]!=str_p_v[j])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.wordPattern("abba", "dog cat cat dog")<<endl;
    cout<<s.wordPattern("abba", "dog cat cat fish")<<endl;
    cout<<s.wordPattern("aaaa", "dog cat cat dog")<<endl;
    cout<<s.wordPattern("abba", "dog dog dog dog")<<endl;
    return 0;
}
