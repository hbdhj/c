// the general method for sort
#include "stdio.h"

void printList(int *pDataArray, int iDataNum)
{
    for (int i = 0; i < iDataNum - 1; i++)
        printf("%d ", pDataArray[i]);
    printf("%d\n", pDataArray[iDataNum-1]);
}

void DataSwap(int* data1, int* data2)
{
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

// the input array
int testArray[] = {1,3,2,6,4,7,8,5,9,0};
int dataNum = sizeof(testArray)/sizeof(int);
