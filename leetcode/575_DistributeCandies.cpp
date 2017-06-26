#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int diff = 1;
        for (int i=1; i<candies.size(); i++)
        {
            if (candies[i]!=candies[i-1])
                diff++;
        }
        return candies.size()/2>diff?diff:candies.size()/2;
    }
};

int main()
{
    Solution s;
    int myints1[] = {1,1,2,2,3,3};
    vector<int> v1 (myints1, myints1 + sizeof(myints1) / sizeof(int) );
    cout<<"result = "<<s.distributeCandies(v1)<<endl;
    int myints2[] = {1,1,2,3};
    vector<int> v2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
    cout<<"result = "<<s.distributeCandies(v2)<<endl;
    int myints3[] = {0,0,0,0,2,3};
    vector<int> v3 (myints3, myints3 + sizeof(myints3) / sizeof(int) );
    cout<<"result = "<<s.distributeCandies(v3)<<endl;
    return 0;
}
