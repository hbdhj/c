/*

Correctness and the Loop Invariant

Sample Input #1

6
1 4 3 5 6 2 

Sample Output #1

1 2 3 4 5 6 

Sample Input #2

6
6 5 4 3 2 1

Sample Output #2

1 2 3 4 5 6 

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int N, int arr[]) {
    int i,j;
    int value;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        j=i-1;
        //while(j>0 && value<arr[j]) // this line will cause the first element will not be sorted
        while(j>=0 && value<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=value;
    }
    for(j=0;j<N;j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }
}
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}