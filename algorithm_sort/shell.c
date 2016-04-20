/*
bubble sort is a kind of simple but highly inefficient sorts
*/
#include "sort.h"

void shellsort1(int* a, int n)
{  
    int i, j, gap;  
  
    for (gap = n / 2; gap > 0; gap /= 2) //步长
    {
        for (i = 0; i < gap; i++)        //直接插入排序  
        {  
            for (j = i + gap; j < n; j += gap)
            {
                if (a[j] < a[j - gap])  
                {  
                    int temp = a[j];  
                    int k = j - gap;  
                    while (k >= 0 && a[k] > temp)  
                    {  
                        a[k + gap] = a[k];  
                        k -= gap;  
                    }  
                    a[k + gap] = temp;  
                }
            }
        }
    }
}

void shellsort2(int a[], int n)  
{  
    int j, gap;  
      
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (j = gap; j < n; j++)//从数组第gap个元素开始
        {
            if (a[j] < a[j - gap])//每个元素与自己组内的数据进行直接插入排序  
            {  
                int temp = a[j];  
                int k = j - gap;  
                while (k >= 0 && a[k] > temp)  
                {  
                    a[k + gap] = a[k];  
                    k -= gap;  
                }  
                a[k + gap] = temp;  
            }
        }
    }
}

void shellsort3(int *a, int n)  
{  
    int i, j, gap;  
  
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        printf("gap = %d\n", gap);
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
            {
                DataSwap(&a[j - 1], &a[j]);
                printDataSwap('i', i, 'j', j);
                printList(a, n);
            }
        }
    }
}

void sort(int* pDataArray, int iDataNum)
{
    shellsort3(pDataArray, iDataNum);
}