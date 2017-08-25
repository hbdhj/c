#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int start_msec = clock();
    // sleep(1);
    int n_num = 1000000;
    int *a = (int*)malloc(sizeof(int)*n_num);
    int *b = (int*)malloc(sizeof(int)*n_num);
    int *c = (int*)malloc(sizeof(int)*n_num);
    for (int i = 0; i < n_num; i++) {
        a[i] = random()%65535+1;
        b[i] = random()%65535+1;
    }
    int end_msec = clock();
    printf("%d msec used to generate %d random numbers\n", end_msec - start_msec, n_num*2);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] + b[i];
    }
    end_msec = clock();
    printf("%d msec used to add %d random numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] - b[i];
    }
    end_msec = clock();
    printf("%d msec used to minus %d random numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] * b[i];
    }
    end_msec = clock();
    printf("%d msec used to times %d random numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] / b[i];
    }
    end_msec = clock();
    printf("%d msec used to divide %d random numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] % b[i];
    }
    end_msec = clock();
    printf("%d msec used to mod %d random numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] > b[i];
    }
    end_msec = clock();
    printf("%d msec used to compare %d random numbers\n", end_msec - start_msec, n_num);
    return 0;
}
