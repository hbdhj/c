// algo:  hash table, bit sort
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length())
            return false;
        if (s.length()==0)
            return true;
        vector<int> sv(26, 0), tv(26, 0);
        for (int i=0; i<s.length(); i++) {
            sv[s[i]-'a']++;
            tv[t[i]-'a']++;
        }
        for (int i=0; i<26; i++) {
            if (sv[i]!=tv[i])
                return false;
        }
        return true;
    }
};
