/*
insertion sort is a kind of sample sort algorithm
*/

#include "sort.h"

void FrontInsertSort(int* pDataArray, int iDataNum)
{
    for (int i = 1; i < iDataNum; i++)
    {
        int j = 0;
        while (j < i && pDataArray[j] <= pDataArray[i])
            j++;

        if (j < i)
        {
            int k = i;
            int temp = pDataArray[i];
            while (k > j)
            {
                pDataArray[k] = pDataArray[k-1];
                k--;
            }
            pDataArray[k] = temp;
        }
    }
}