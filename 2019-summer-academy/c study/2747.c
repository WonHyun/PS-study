#include "test.h"
#if (PNUM == 2747)
//포인터로배열 인덱스 옮기기
#include <stdio.h>

int func(const int** p)
{
	int sum = 0;

	printf("=========%d\n", (*p)[0]);

	for (int i = 0; i < (*p)[0]; i++) {
		sum += (*p)[i + 1];
	}

	*p += (*p)[0] + 1;

    /*
    int i, sum;
    printf("=========%d\n", (*p)[0]);

    for (int i = 1; i <= (*p)[0]; i++) {
        sum += (*p)[i];
    }

    *p += i;

    */

	return sum;
}

void main(void)
{
	int a[] = { 1, 10, 2, -5, -20, 3, 100, 200, 300, 4, -10, -20, -30, -40 };
	const int* p = a;

	for (int i = 0; i < 4; i++)
	{
		printf("SUM=%d\n", func(&p));
	}
}
#endif
