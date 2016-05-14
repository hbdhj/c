class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while (n) {
            char a = 'A'+(n-1)%26;
            ret = a + ret;
            n = (n-1)/26;
        }
        return ret;
    }
};
