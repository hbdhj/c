#include "common.h"

class Solution {
public:
    bool isUgly(int num) {
        cout<<"isUgly("<<num<<") return ";
        if (num<1)
            return false;
        if (num==1)
            return true;
        //cout<<num<<endl;
        while((num%2==0)&&(num>1))
            num=num/2;
        //cout<<num<<endl;
        while((num%3==0)&&(num>1))
            num=num/3;
        //cout<<num<<endl;
        while((num%5==0)&&(num>1))
            num=num/5;
        //cout<<num<<endl;
        if (num==1)
            return true;
        return false;
    }
};

int main() {
    Solution s;
    cout<<s.isUgly(1)<<endl;
    cout<<s.isUgly(2)<<endl;
    cout<<s.isUgly(3)<<endl;
    cout<<s.isUgly(4)<<endl;
    cout<<s.isUgly(5)<<endl;
    cout<<s.isUgly(6)<<endl;
    cout<<s.isUgly(7)<<endl;
    cout<<s.isUgly(8)<<endl;
    cout<<s.isUgly(9)<<endl;
    cout<<s.isUgly(10)<<endl;
    cout<<s.isUgly(11)<<endl;
    cout<<s.isUgly(12)<<endl;
    cout<<s.isUgly(13)<<endl;
    cout<<s.isUgly(14)<<endl;
    cout<<s.isUgly(15)<<endl;
    cout<<s.isUgly(16)<<endl;
    cout<<s.isUgly(17)<<endl;
    return 0;
}
