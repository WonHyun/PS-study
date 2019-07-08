#include "test.h"
#if (PNUM == 3512)
//자릿수 계산문제
#include <stdio.h>

int calPosition(int n) {
	int pos = 0;
	while (n != 0) {
		n /= 10;
		pos++;
	}
	return pos;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", calPosition(n));
	return 0;
}
#endif