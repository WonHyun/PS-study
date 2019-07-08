#include "test.h"
#if (PNUM == 3522)
//배열출력 위치변환
#include <stdio.h>

void main() {
	int a[3][4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
}
#endif