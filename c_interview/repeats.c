//GOOGLE???  
//?????n???,?????????[0, n-1],?????????,??????????,??O(1)???O(n)???  
//By MoreWindows (http://blog.csdn.net/MoreWindows)  
#include <stdio.h>  
const int NO_REPEAT_FLAG = -1;  
int FindRepeatNumberInArray(int *a, int n)  
{  
    for(int i = 0; i < n; i++)  
    {  
        int nRealIndex = a[i] >= n ? a[i] - n : a[i];  
        if (a[nRealIndex] >= n) //?????????n???????????????  
            return nRealIndex;  
        else  
            a[nRealIndex] += n;  
    }  
    return NO_REPEAT_FLAG; //?????????  
}  
void PrintfArray(int a[], int n)  
{  
    for (int i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    putchar('\n');  
}  
int main()  
{  
    //printf("    ??????????? ?????GOOGLE?????2\n");        
    //printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");   
  
    const int MAXN = 10;  
    //int a[MAXN] = {2, 4, 1, 5, 7,  6, 1, 9, 0, 2};  
    int a[MAXN] = {0, 1, 2, 3, 4,  5, 6, 7, 8, 0};  
      
    printf("Array is: \n");  
    PrintfArray(a, MAXN);  
  
    int nRepeatNumber = FindRepeatNumberInArray(a, MAXN);  
    if (nRepeatNumber != NO_REPEAT_FLAG)  
        printf("Got repeates, it is %d\n", nRepeatNumber);  
    else  
        printf("No repeats\n");  
    return 0;  
}