/*
bubble sort is a kind of simple but highly inefficient sorts
*/
#include "sort.h"

void BubbleSort(int* pDataArray, int iDataNum)
{
    for (int i = 0; i < iDataNum - 1; i++)
        for (int j = 0; j < iDataNum - i - 1; j++)
            if (pDataArray[j] > pDataArray[j + 1])
                DataSwap(&pDataArray[j], &pDataArray[j + 1]);
}

int main()
{
    printList(testArray, dataNum);
    BubbleSort(testArray, dataNum);
    printList(testArray, dataNum);
    return 0;
}
