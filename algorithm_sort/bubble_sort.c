/*
bubble sort is a kind of simple but highly inefficient sorts
*/
#include "sort.h"

void BubbleSort1(int* pDataArray, int iDataNum)
{
    for (int i = 0; i < iDataNum - 1; i++)
        for (int j = 0; j < iDataNum - i - 1; j++)
            if (pDataArray[j] > pDataArray[j + 1])
                DataSwap(&pDataArray[j], &pDataArray[j + 1]);
}

//冒泡排序2  
void BubbleSort2(int a[], int n)  
{  
    int j, k;  
    bool flag;  
      
    k = n;  
    flag = true;  
    while (flag)  
    {  
        flag = false;  
        for (j = 1; j < k; j++)
        {
            if (a[j - 1] > a[j])  
            {  
                DataSwap(a[j - 1], a[j]);  
                flag = true;  
            }  
        }
        k--;
    }
}

//冒泡排序3  
void BubbleSort3(int a[], int n)  
{  
    int j, k;  
    int flag;  
      
    flag = n;  
    while (flag > 0)  
    {  
        k = flag;  
        flag = 0;  
        for (j = 1; j < k; j++)
        {
            if (a[j - 1] > a[j])  
            {  
                DataSwap(a[j - 1], a[j]);  
                flag = j;  
            }
        }
    }  
}

int main()
{
    printList(testArray, dataNum);
    BubbleSort(testArray, dataNum);
    printList(testArray, dataNum);
    return 0;
}
