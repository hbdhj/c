/*

Intro to Tutorial Challenges

Sample Input

4
6
1 4 5 7 9 12

Sample Output

1

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

    int N,Z;
    scanf("%d", &Z);
    scanf("%d", &N);
    int arr[N], i, j;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i]==Z)
           j=i;
    }

    printf("%d", j);
    
    return 0;
}