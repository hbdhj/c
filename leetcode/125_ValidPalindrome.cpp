class Solution {
public:
    char compare(char c1) {
        if (c1>='A'&&c1<='Z')
            return c1+'a'-'A';
        return c1;
    }
    bool compare(char c1, char c2) {
        if (c1==c2)
            return true;
        char lc1 = compare(c1);
        char lc2 = compare(c2);
        return lc1==lc2;
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<end) {
            while ((s[start]<'A'||s[start]>'Z')&&(s[start]<'a'||s[start]>'z')&&(s[start]<'0'||s[start]>'9')&&(start<end))
                start++;
            while ((s[end]<'A'||s[end]>'Z')&&(s[end]<'a'||s[end]>'z')&&(s[end]<'0'||s[end]>'9')&&(start<end))
                end--;
            if (compare(s[start], s[end])==false) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
};
