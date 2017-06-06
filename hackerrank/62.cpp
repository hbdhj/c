/*

Copyright 2017 <Deng Haijun>

Tutorials > 10 Days of Statistics > Day 0: Mean, Median, and Mode 

Sample Input

10
64630 11735 14216 99233 14470 4978 73429 38120 51135 67060

Sample Output

43900.6
44627.5
4978

*/

#include "./common.h"

int main(){
    int n, xi;
	cin >> n;
	vector<int> xis(n);
	float mean;
	for (int i = 0; i < n; i++) {
		cin >> xis[i];
		mean += xis[i] / n;
	}
	printf("%.1f", mean);
	sort(xis.begin(), xis.end());
	if (n%2) {
		printf("%.1f", xis[n/2]);
	} else {
		printf("%.1f", float(xis[n/2] + xis[n/2-1])/2);
	}
	int max_freq = 0;
	int min_val = 0;
    return 0;
}
