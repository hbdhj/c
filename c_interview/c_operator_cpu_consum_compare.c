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
    float *d = (float*)malloc(sizeof(float)*n_num);
    for (int i = 0; i < n_num; i++) {
        a[i] = random()%65525+3;
        b[i] = random()%65525+5;
    }
    /*for (int i = 0; i < n_num; i++) {
		printf("%d %d\n", a[i], b[i]);
	}*/
    int end_msec = clock();
    printf("%d msec used to generate %d random integer numbers\n", end_msec - start_msec, n_num*2);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] + b[i];
    }
    end_msec = clock();
    printf("%d msec used to add %d random integer numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] - b[i];
    }
    end_msec = clock();
    printf("%d msec used to minus %d random integer numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] * b[i];
    }
    end_msec = clock();
    printf("%d msec used to times %d random integer numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        a[i] = (c[i] + 7 ) / (b[i] + 3);
    }
    end_msec = clock();
    printf("%d msec used to divide %d random integer numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        a[i] = (c[i] + 7 ) % (b[i] + 3);
    }
    end_msec = clock();
    printf("%d msec used to mod %d random integer numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        c[i] = a[i] > b[i];
    }
    end_msec = clock();
    printf("%d msec used to compare %d random integer numbers\n", end_msec - start_msec, n_num);
    start_msec = clock();
    for (int i = 0; i < n_num; i++) {
        d[i] = (float)(c[i]+7)/(float)(b[i]+3);
    }
    end_msec = clock();
    printf("%d msec used to divide %d random float numbers\n", end_msec - start_msec, n_num);
    return 0;
}
