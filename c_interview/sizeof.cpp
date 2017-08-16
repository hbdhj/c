#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

struct S1 {
	int i;
	char ch1;
	char ch2;
};

struct S2 {
	char ch1;
	int i;
	char ch2;
};

union U1 {
	struct S1 S11;
	struct S2 S21;
};

struct S3 {
	char a[13];
};

struct S4 {
	int i;
	U1 u;
};

#pragma pack(1)
struct S5 {
	int i;
	char ch1;
	char ch2;
};
#pragma pack()

struct EmptyS1 {
	
};

class EmptyS2 {
	
};

union U2 {
	char a[13];
	int b;
	EmptyS1 es1;
};

#pragma pack(1)
union U3 {
	char a[13];
	int b;
	EmptyS1 es1;
};
#pragma pack()

class A {
private:
    int a1;
    char a2;
    char a3;
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

class J {

};

int main(int argc, char** argv)
{
    char c[10];
    printf("sizeof(S1) = %lu\n", sizeof(S1));
    printf("sizeof(S2) = %lu\n", sizeof(S2));
    printf("sizeof(S3) = %lu\n", sizeof(S3));
    printf("sizeof(S4) = %lu\n", sizeof(S4));
    printf("sizeof(S5) = %lu\n", sizeof(S5));
    printf("sizeof(U1) = %lu\n", sizeof(U1));
    printf("sizeof(U2) = %lu\n", sizeof(U2));
    printf("sizeof(U3) = %lu\n", sizeof(U3));
    printf("sizeof(EmptyS1) = %lu\n", sizeof(EmptyS1));
	printf("sizeof(EmptyS2) = %lu\n", sizeof(EmptyS2));
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
    printf("sizeof(a empty class) = %lu\n", sizeof(J));
    exit(0);
}
