#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
	printf("Hello");
	fork();
	printf("Hello");
	return 0;
}

