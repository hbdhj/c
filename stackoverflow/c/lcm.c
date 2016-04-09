#include <stdio.h>
#include <math.h>

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a%b);
}

long lcm(long a, long b) {
    return (a * b) / gcd(a,b);
}

int main() {

    long a;
    long b;

    scanf("%ld %ld", &a, &b);
    printf("%ld %ld\n", a, b);
    printf("%ld\n", lcm(a,b));

    return 0;
}
