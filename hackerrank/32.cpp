/*
Sample Input

8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output

Yes
No
No

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<int> s;
    int n, y, x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>y>>x;
        switch(y) {
            case 1:
            {
                set<int>::iterator itr=s.find(x);
                if(itr==s.end())
                    s.insert(x);
            }
            break;
            case 2:
            {
                set<int>::iterator itr=s.find(x);
                if(itr!=s.end())
                    s.erase(x);
            }
            break;
            case 3:
            {
                set<int>::iterator itr=s.find(x);
                if(itr==s.end())
                    cout<<"No"<<endl;
                else
                    cout<<"Yes"<<endl;
            }
            break;
            default:
            break;
        }
    }
    return 0;
}
