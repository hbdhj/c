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
        //cout<<"diff = "<<diff<<"candies.size()/2 = "<<candies.size()/2<<endl;
        return candies.size()/2>diff?diff:candies.size()/2;
    }
};

int main()
{
    int myints[] = {1,1,2,2,3,3};
    vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );
    Solution s;
    cout<<"result = "<<s.distributeCandies(v1)<<endl;
    int myints2[] = {1,1,2,3};
    vector<int> v2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
    cout<<"result = "<<s.distributeCandies(v2)<<endl;
    int myints2[] = {0,0,0,0,2,3};
    vector<int> v2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
    cout<<"result = "<<s.distributeCandies(v2)<<endl;
    return 0;
}
