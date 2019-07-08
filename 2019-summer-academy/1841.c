#include "test.h"
#if (PNUM == 1841)
//test 3번 최댓값 문제
#include <stdio.h>

int main(void)
{
	int cur, maxIdx = 1, max = -1;
	for (int i = 1; i < 10; i++) {
		scanf("%d", &cur);
		if (cur > max) { max = cur; maxIdx = i; }
	}

	printf("%d\n%d",max, maxIdx);

	return 0;
}
#endif