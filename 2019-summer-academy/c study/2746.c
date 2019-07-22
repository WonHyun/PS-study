#include "test.h"
#if (PNUM == 2746)
//swqp 구현
#include <stdio.h>

void Swap(int *p, int *q)
{
	int *temp;
	temp = *p;
	*p = *q;
	*q = temp;

	/*
	*p ^= *q;
	*q ^= *p;
	*p ^= *q;
	*/
}

void main(void)
{
	int a = 10, b = 20;

	printf("Before : %d %d\n", a, b);
	Swap(&a, &b);
	printf("After : %d %d\n", a, b);
}
#endif
