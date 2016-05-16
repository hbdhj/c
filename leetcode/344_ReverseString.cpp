class Solution {
public:
    string reverseString(string s) {
        int si = 0;
        int ei = s.length()-1;
        while(si<ei) {
            char tmp = s[ei];
            s[ei] = s[si];
            s[si] = tmp;
            si++;
            ei--;
        }
        return s;
    }
};
