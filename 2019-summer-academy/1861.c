#include "test.h"
#if (PNUM == 1861)
//test 4번 지능형 기차
#include <stdio.h>

int main(void)
{
	int ride, exit, cur = 0, max = 0;

	for (int i = 0; i < 4; i++) {
		scanf("%d", &exit);
		scanf("%d", &ride);
		ride -= exit;
		cur += ride;
		if (cur > max) { max = cur; }
	}

	printf("%d",max);

	return 0;
}
#endif