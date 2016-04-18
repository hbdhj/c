/*
bubble sort is a kind of simple but highly inefficient sorts
*/
#include "sort.h"

void Selectsort(int* a, int n)  
{  
    int i, j, nMinIndex;  
    for (i = 0; i < n; i++)  
    {  
        nMinIndex = i; //找最小元素的位置  
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[nMinIndex])
            {
                nMinIndex = j;
            }
        }
        DataSwap(&a[i], &a[nMinIndex]); //将这个元素放到无序区的开头
        printDataSwap('i', i, 'j', nMinIndex);
        printList(a, n);
    }  
} 

void sort(int* pDataArray, int iDataNum)
{
    Selectsort(pDataArray, iDataNum);
}