/*
insertion sort is a kind of sample sort algorithm
*/

#include "sort.h"

void BackInsertSort(int* pDataArray, int iDataNum)
{
    for (int i = 1; i < iDataNum; i++)
    {
        int j = i - 1;
        int temp = pDataArray[i];
        while (j >= 0 && pDataArray[j] > temp)
        {
            pDataArray[j+1] = pDataArray[j];
            j--;
        }

        if (j != i - 1)
            pDataArray[j+1] = temp;
    }
}

int main()
{
    printList(testArray, dataNum);
    BackInsertSort(testArray, dataNum);
    printList(testArray, dataNum);
    return 0;
}
