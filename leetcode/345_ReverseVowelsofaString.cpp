class Solution {
public:
    bool isVowels(char c) {
        return (c=='A')||(c=='E')||(c=='I')||(c=='O')||(c=='U')||(c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u');
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() -1;
        while(i<j) {
            while(isVowels(s[i])==false)
                i++;
            while(isVowels(s[j])==false)
                j--;
            if (i<j) {
                char tmp = s[j];
                s[j] = s[i];
                s[i] = tmp;
                i++;
                j--;
            }
        }
        return s;
    }
};
