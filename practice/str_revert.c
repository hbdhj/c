/*
*/

#include <string.h>
#include <stdio.h>  // error 1, miss this include for printf
#include <stdlib.h> // error 2, miss this include for malloc

// main() { // warning better to add the return
int main() {
    char* src = "hello world";
    char* dest= NULL;
    int len=strlen(src);
    dest=(char*)malloc(len);
    char* d=dest;
    // char* s=src[len];  //error 3 need to get the address
    char* s=&(src[len-1]);
    while(len--!=0) {
        // *d++=*s--;  //error 4 need to get the char not the pointer
        *d++=*s--;
    }
    printf("%s\n", dest);
    // better to release the memory
    free(dest);
    return 0;
}