#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    /*
    int ret = 0;
    for (int i = 0; i<q.size(); i++)
    {
        if (q[i] > (i + 3)) {
            cout<<"Too chaotic";
            return;
        }
        else if (q[i] > (i + 1))
            ret += (q[i] - i -1);
    }
    cout<<ret;*/
    vector<int> c(q.size(), 0);
    int tmp;
    bool swap;
    int swap_count = 0;
    do {
        swap = false;
        for (int i = 1; i<q.size(); i++) {
            if (q[i] < q[i-1]) {
                //cout<<"c["<<q[i-1]<<"] = "<<c[q[i-1]-1]<<endl;
                if (c[q[i-1]-1]<2) {
                    c[q[i-1]-1]++;
                    tmp = q[i-1];
                    q[i-1] = q[i];
                    q[i] = tmp;
                    swap = true;
                    swap_count ++;
                } else {
                    cout<<"Too chaotic"<<endl;
                    return;
                }
            }
        }
        //cout<<swap<<" "<<swap_count<<endl;
    } while (swap);
    cout<<swap_count<<endl;
}


int main()
{
    //int myints[] = {2, 1, 5, 3, 4}; // 3
    
    //int myints[] = {2, 5, 1, 3, 4};  // Too chaotic
    int myints[] = {1, 2, 5, 3, 7, 8, 6, 4};  // 7
    std::vector<int> c (myints, myints + sizeof(myints) / sizeof(int) );
    minimumBribes(c);

    return 0;
}
