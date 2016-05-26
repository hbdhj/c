#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int strToBits(const char *str) {
    unsigned int ret = 0;
    while((*str)!='\0') {
        //printf("%c %d", *str, (*str-'a'));
        ret|=1<<(*str-'a');
        str++;
    }
    return ret;
}

int maxProduct(char** words, int wordsSize) {
    unsigned int* bits = malloc(sizeof(unsigned int)*wordsSize);
    unsigned int* lens = malloc(sizeof(unsigned int)*wordsSize);
    for (int i = 0; i<wordsSize; i++) {
        bits[i] = strToBits(words[i]);
        lens[i] = strlen(words[i]);
    }
/*
    for (int i = 0; i<wordsSize; i++) {
        printf("%d %d\n", bits[i], lens[i]);
    }
*/
    int ret = 0;
    for (int i = 0; i<wordsSize-1; i++) {
        for (int j = i+1; j<wordsSize; j++) {
            //printf("%s %s %d&%d = %d\n", words[i], words[j], bits[i], bits[j], bits[i]&bits[j]);
            if ((bits[i]&bits[j])==0) {
                if (ret<(lens[i]*lens[j])) {
                    ret=lens[i]*lens[j];
                }
            }
        }
    }
    return ret;
}

int UnitTest1 () {
    const char *a[6];
    a[0] = "abcw";
    a[1] = "baz";
    a[2] = "foo";
    a[3] = "bar";
    a[4] = "xtfn";
    a[5] = "abcdef";
    printf("%d\n", maxProduct(a, 6));
    return 0;
}

int UnitTest2 () {
    const char *a[7];
    a[0] = "a";
    a[1] = "ab";
    a[2] = "abc";
    a[3] = "d";
    a[4] = "cd";
    a[5] = "bcd";
    a[6] = "abcd";
    printf("%d\n", maxProduct(a, 7));
    return 0;
}

int UnitTest4 () {
    const char *a[4];
    a[0] = "a";
    a[1] = "aa";
    a[2] = "aaa";
    a[3] = "aaaa";
    printf("%d\n", maxProduct(a, 4));
    return 0;
}

int UnitTest3 () {
    const char *a[2];
    a[0] = "ab";
    a[1] = "cd";
    printf("%d\n", maxProduct(a, 2));
    return 0;
}

int main() {
    UnitTest1();
    UnitTest2();
    UnitTest3();
    UnitTest4();
    return 0;
}
