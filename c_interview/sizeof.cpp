#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

class A {
private:
    int a1;
    char a2;
};

class B : public A{
private:
    int b1;
    char b2;
};

class C {
private:
    int c1;
    char c2;
protected:
    virtual int f_c3() {
        return 0;
    }
};

class D : public C{
private:
    int d1;
    char d2;
protected:
    virtual int f_d3() {
        return 0;
    }
};

class E : public C{
private:
    int e1;
    char e2;
protected:
    virtual int f_c3() {
        return 0;
    }
};

struct F {
    int f1;
    char f2;
};

union G{
    char g1;
    int g2;
    double g3;
};

union H{
    double h1;
    int h2;
    char h3;
};

enum I{
    pencil,
    pen
};

int main(int argc, char** argv)
{
    char c[10];
    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(double) = %lu\n", sizeof(double));
    printf("sizeof(char c[10]) = %lu\n", sizeof(c));
    printf("sizeof(a normal class) = %lu\n", sizeof(A));
    printf("sizeof(a normal sub-class) = %lu\n", sizeof(B));
    printf("sizeof(a class with virtual method) = %lu\n", sizeof(C));
    printf("sizeof(a sub-class with a new virtual method) = %lu\n", sizeof(D));
    printf("sizeof(a sub-class with overloaded virtual method) = %lu\n", sizeof(E));
    printf("sizeof(a normal struct) = %lu\n", sizeof(F));
    printf("sizeof(a union) = %lu\n", sizeof(G));
    printf("sizeof(another union) = %lu\n", sizeof(H));
    printf("sizeof(a enum) = %lu\n", sizeof(I));
    exit(0);
}
