#include "test.h"
#if (PNUM == 3486)
//3 5 의 배수
#include <stdio.h>
int f1(int num)
{
	return (num % 3 == 0) || (num % 5 == 0) ? 1 : 0;
}

void main(void)
{
	int num;
	scanf("%d", &num);
	printf("%s", (f1(num) ? "YES" : "NO"));
}
#endif