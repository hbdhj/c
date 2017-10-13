/*
Copyright 2017 <Deng Haijun>

// O2 will make the program run fast, can be removed
gcc gprof_example.cc -pg -o gprof_example -O2 -lc
gcc gprof_example.cc -pg -o gprof_example -g

./gprof_example 50000

// flat profile
gprof gprof_example gmon.out -p

// call graph
gprof example1 gmon.out -q

// call count with source code, should compiled with -g
gprof gprof_example gmon.out -A
*/

#include <cstdlib>
#include <stdio.h>

int a(void) {
    int i = 0, g = 0;
    while (i++ < 100000) {
        g += i;
    }
    return g;
}

int b(void) {
    int i = 0, g = 0;
    while (i++ < 400000) {
        g += i;
    }
    return g;
}

int main(int argc, char** argv) {
    printf("argc = %d\n", argc);
    int iterations;
    if (argc != 2) {
        printf("Usage %s <No of Iterations>\n", argv[0]);
        exit(-1);
    } else {
        iterations = atoi(argv[1]);
    }
    printf("No of iterations = %d\n", iterations);
    while (iterations--) {
        a();
        b();
    }
    return 0;
}
