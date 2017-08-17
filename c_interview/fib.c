#include <stdio.h>
#include <stdlib.h>

// 1 1 2 3 5 8

// time O(n^2) space (1)
int fib_v1(int n) {
	if (n==1 || n==2) {
		return 1;
	} else {
		return fib_v1(n-1) + fib_v1(n-2);
	}
}

// time O(n^2) space (1)
int fib_v2(int n) {
	if (n < 1)
		return 0;
	else if (n==1 || n==2) {
		return 1;
	} else {
		return fib_v2(n-1) + fib_v2(n-2);
	}
}

// time O(n) space (n)
int fib_v3(int n) {
	if (n < 1)
		return 0;
	else if (n==1 || n==2) {
		return 1;
	} else {
		int* res = new int[n];
		res[0] = res[1] = 1;
		for (int i = 2; i<n; i++ )
			res[i] = res[i-1] + res[i-2];
		return res[n-1];
	}
}

// time O(n) space (1)
int fib_v4(int n) {
	if (n < 1)
		return 0;
	else if (n==1 || n==2) {
		return 1;
	} else {
		int f1 = 1, f2 = 1, ret;
		for (int i = 2; i<n; i++ ) {
			//printf("i = %d, f1 = %d, f2 = %d, ret = %d\n", i, f1, f2, ret);
			ret = f1 + f2;
			f1 = f2;
			f2 = ret;
			//printf("i = %d, f1 = %d, f2 = %d, ret = %d\n", i, f1, f2, ret);
		}
		return ret;
	}
}

// cal max fib = 46
int max_fib() {
	int max_int = 0x7fffffff;
	int f1 = 1, f2 = 1, i = 2, ret;
	for (i = 2; i<max_int; i++ ) {
		//printf("i = %d, f1 = %d, f2 = %d, ret = %d\n", i, f1, f2, ret);
		if (f1 > (max_int - f2))
			break;
		ret = f1 + f2;
		f1 = f2;
		f2 = ret;
		//printf("i = %d, f1 = %d, f2 = %d, ret = %d\n", i, f1, f2, ret);
	}
	return i;
}

// time O(n) space (1)
int fib_v5(int n) {
	if (n < 1 || n > 46)
		return 0;
	else if (n==1 || n==2) {
		return 1;
	} else {
		int f1 = 1, f2 = 1, ret;
		for (int i = 2; i<n; i++ ) {
			//printf("i = %d, f1 = %d, f2 = %d, ret = %d\n", i, f1, f2, ret);
			ret = f1 + f2;
			f1 = f2;
			f2 = ret;
			//printf("i = %d, f1 = %d, f2 = %d, ret = %d\n", i, f1, f2, ret);
		}
		return ret;
	}
}

int fib_nums[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};

// time O(1) space (1)
int fib_v6(int n) {
	if (n < 1 || n > 46)
		return 0;
	else{
		return fib_nums[n-1];
	}
}

int main(int argc, char** argv) {
	printf("fib_v1(3) = %d\n", fib_v1(3));
	printf("fib_v2(4) = %d\n", fib_v2(4));
	printf("fib_v3(5) = %d\n", fib_v3(5));
	printf("fib_v4(6) = %d\n", fib_v4(6));
	printf("fib_v5(7) = %d\n", fib_v5(7));
	printf("fib_v6(8) = %d\n", fib_v6(8));
	printf("sizeof(int) = %d\n", sizeof(int));
	int max_int = 0x7fffffff;
	int max_int_1 = max_int +  1;
	printf("max_int = %d, max_int + 1 = %d\n", max_int, max_int_1);
	int max_fib_n = max_fib();
	printf("max_fib_n = %d, fib_v3(%d) = %d\n", max_fib_n, max_fib_n, fib_v3(max_fib_n));
	printf("fib_v4(%d) = %d\n", max_fib_n+1, fib_v4(max_fib_n+1));
	printf("fib_v5(%d) = %d\n", max_fib_n+1, fib_v5(max_fib_n+1));
}