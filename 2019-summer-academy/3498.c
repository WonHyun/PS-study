#include "test.h"
#if (PNUM == 3498)
//최댓값
#include <stdio.h>

void main(void)
{
	int arr[10] = { 3, 4, -10, 59, 32, 48, 22, 77, -99, 9 };
	int max = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);
		if (max < arr[i]) max = arr[i];
	}
	printf("\nMAX = %d", max);
}
#endif