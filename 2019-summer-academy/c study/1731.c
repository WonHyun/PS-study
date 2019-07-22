#include "test.h"
#if (PNUM == 1731)
//test 5번, 문자사각형1
#include <stdio.h>

int main(void)
{
	char ch = 'A';
	int n;

	scanf("%d",&n);

	for (int i = n - 1; i > -1; i--) {
		for (int j = n - 1; j > -1; j--) {
			int cur = ch + (j * n + i) % 26;
			printf("%c ",cur);
		}

		printf("\n");
	}

	return 0;
}
#endif