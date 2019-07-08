#include "test.h"
#if (PNUM == 3382)
//test 2번 연속한 곱들의 합계
#include <stdio.h>

int main(void)
{
	int n, cur, sum = 0;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		cur = 1;
		for (int j = 1; j <= i; j++) {
			cur *= j;
		}
		sum += cur;
	}

	printf("%d",sum);

	return 0;
}
#endif