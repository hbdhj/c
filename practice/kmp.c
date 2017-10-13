#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *compute_prefix_function(char *pattern, int psize)
{
    int k = -1;
    int i = 1;
    int *pi = malloc(sizeof(int)*psize);
    if (!pi)
        return NULL;

    pi[0] = k;
    for (i = 1; i < psize; i++) {
        while (k > -1 && pattern[k+1] != pattern[i])
            k = pi[k];
        if (pattern[i] == pattern[k+1])
            k++;
        pi[i] = k;
    }
    printf("pi = :");
    for (i = 0; i < psize; i++) {
        printf("%d ", pi[i]);
    }
    printf("\n");
    return pi;
}

int kmp(char *target, int tsize, char *pattern, int psize)
{
    int i;
    int *pi = compute_prefix_function(pattern, psize);
    int k = -1;
    if (!pi)
        return -1;
    for (i = 0; i < tsize; i++) {
        while (k > -1 && pattern[k+1] != target[i]) {
            //printf("reset k = %d to %d", k, pi[k]);
            printf("pattern[k+1=%d]=%c != target[%d]=%c, reset k to %d\n", k+1, pattern[k+1], i, target[i], pi[k]);
            k = pi[k];
        }
        // match continue to next char
        if (target[i] == pattern[k+1]) { 
            printf("target[%d]=%c == pattern[%d]=%c, k++\n", i, target[i], k+1, pattern[k+1]);
            k++;
        }
        if (k == psize - 1) { // k reach the last in pattern so find
            free(pi);
            return i-k;
        }
    }
    free(pi);
    return -1;
}

int main(int argc, const char *argv[])
{
    char target[] = "ABC ABCDAB ABCDABCDABDE";
    char *ch = target;
    char pattern[] = "ABCDABD";
    int i;
	printf("target = %s , pattern = %s\n", target, pattern);
    i = kmp(target, strlen(target), pattern, strlen(pattern));
    if (i >= 0)
        printf("matched @: %s\n", ch + i);
    return 0;
}
