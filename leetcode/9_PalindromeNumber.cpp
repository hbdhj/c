#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        long n = 0;
        int i=x;
        while(i>0) {
            n=n*10+i%10;
            i=i/10;
        }
        if (n==x)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(1)<<endl;
    cout<<s.isPalindrome(121)<<endl;
    cout<<s.isPalindrome(123)<<endl;
}
