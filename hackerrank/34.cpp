/*

Grid Challenge

Sample Input

1
5
ebacd
fghij
olmkn
trpqs
xywuv

Sample Output

YES

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
//using namespace std;


int main() {
    int t, n;
    std::cin>>t;
    while(t--) {
        std::cin>>n;
        std::vector<std::string>  x(n);
        for(int i=0; i<n; i++ ) {
            std::cin>>x[i];
            std::sort(x[i].begin(), x[i].end());
        }
        bool check = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n-1; j++) {
                if (x[j][i]>x[j+1][i]) {
                    check = false;
                    break;
                }
            }
        }
        if(check)
            std::cout<<"YES"<<std::endl;
        else
            std::cout<<"NO"<<std::endl;
    }
    return 0;
}
