#include <iostream>
#define a 10
int main() {
    printf("%d...",a);
    foo();
    printf("%d", a);
    return 0;
}

void foo() {
    #undef a
    #define a 50
}
