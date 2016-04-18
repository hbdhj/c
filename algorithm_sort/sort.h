// the general method for sort

//#include <stdbool.h>
#include "stdio.h"

void DataSwap(int* data1, int* data2)
{
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

void printList(int *pDataArray, int iDataNum)
{
    for (int i = 0; i < iDataNum - 1; i++)
        printf("%d ", pDataArray[i]);
    printf("%d\n", pDataArray[iDataNum-1]);
}

void printDataSwap(char cl, int l, char cr, int r)
{
    printf("%c = %d, %c = %d\n", cl, l, cr, r);
}

void sort(int* pDataArray, int iDataNum);