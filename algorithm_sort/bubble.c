/*
bubble sort is a kind of simple but highly inefficient sorts
*/
#include "sort.h"

void BubbleSort1(int* pDataArray, int iDataNum)
{
    for (int i = 0; i < iDataNum - 1; i++)
    {
        for (int j = 0; j < iDataNum - i - 1; j++)
        {
            if (pDataArray[j] > pDataArray[j + 1])
            {
                DataSwap(&pDataArray[j], &pDataArray[j + 1]);
            }
        }
    }
}

//冒泡排序2  
void BubbleSort2(int* pDataArray, int iDataNum)
{  
    int j, k;  
    bool flag;  
      
    k = iDataNum;  
    flag = true;  
    while (flag)  
    {  
        flag = false;  
        for (j = 1; j < k; j++)
        {
            if (pDataArray[j - 1] > pDataArray[j])  
            {  
                DataSwap(&pDataArray[j - 1], &pDataArray[j]);  
                flag = true;  
            }  
        }
        k--;
    }
}

//冒泡排序3
void BubbleSort3(int* pDataArray, int iDataNum)
{  
    int j, k;  
    int flag;  
      
    flag = iDataNum;  
    while (flag > 0)  
    {  
        k = flag;  
        flag = 0;  
        for (j = 1; j < k; j++)
        {
            if (pDataArray[j - 1] > pDataArray[j])  
            {  
                DataSwap(&pDataArray[j - 1], &pDataArray[j]);
                printDataSwap('i', j-1, 'j', j);
                printList(pDataArray, iDataNum);
                flag = j;  
            }
        }
    }  
}

void sort(int* pDataArray, int iDataNum)
{
    BubbleSort3(pDataArray, iDataNum);
}