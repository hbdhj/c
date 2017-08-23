#include <stdio.h>


int add(int a, int b) {
    return a + b;
};

int minus(int a, int b) {
    return a - b;
}

int main() {
    int a = 3, b = 2;
    int (*f) (int a, int b);
    f = &add;
    printf("add(%d, %d) = %d\n", a, b, f(a, b));
    f = &minus;
    printf("minus(%d, %d) = %d\n", a, b, f(a, b));
    return 0;
}
