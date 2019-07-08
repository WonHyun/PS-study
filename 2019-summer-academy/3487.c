#include "test.h"
#if (PNUM == 3487)
//사이값찾기
#include <stdio.h>
int f1(int num)
{
	return 3 < num && num < 11 ? 1 : 0;
}

void main(void)
{
	int num;
	scanf("%d", &num);
	printf("%s", (f1(num) ? "YES" : "NO"));
}
#endif