/*
bubble sort is a kind of simple but highly inefficient sorts
*/
#include "sort.h"
#include "data.h"

int main()
{
    printList(testArray, dataNum);
    sort(testArray, dataNum);
    printList(testArray, dataNum);
    return 0;
}
