#include <bits/stdc++.h>
#include <algorithm>
#include <string>

using namespace std;

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    vector<int> steps(c.size(), 0);
    steps[1] = 1;
    for (int i = 2; i<c.size(); i++ ) {
        if (c[i-1])
            steps[i] = steps[i-2] + 1;
        else if (c[i-2])
            steps[i] = steps[i-1] + 1;
        else
            steps[i] = min(steps[i-2], steps[i-2]) + 1;
    }
    return steps[c.size()-1];
}


int main()
{
    //int myints[] = {0, 0, 0, 0, 1, 0};  // 3
    int myints[] = {0, 0, 1, 0, 0, 1, 0}; // 4
    //int myints[] = {0, 1, 0, 1, 0, 1, 0};  //3
    std::vector<int> c (myints, myints + sizeof(myints) / sizeof(int) );
    cout << jumpingOnClouds(c) <<endl;

    return 0;
}
