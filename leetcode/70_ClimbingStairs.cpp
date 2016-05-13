#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n);
        stairs[0] = 1;
        stairs[1] = 2;
        for (int i = 2; i<n; i++)
            stairs[i]=stairs[i-1]+stairs[i-2];
        return stairs[n-1];
    }
};

int main()
{
    Solution s;
    cout<<s.climbStairs(5)<<endl;
    return 0;
}
