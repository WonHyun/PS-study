#include "test.h"
#if (PNUM == 3497)
//행운의 네잎클로버 문제
#include <stdio.h>

void calLucky(int max) {
	int num, sum;
	while (max > 9) {
		num = max;
		sum = 0;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum == 3) return;
		if (sum == 7) printf("%d\n", max);
		max--;
	}

	return;
}

int main() {
	int max;
	scanf("%d", &max);
	calLucky(max);
	return 0;
}
#endif