#include "test.h"
#if (PNUM == 3518)
//절댓값
#include <stdio.h>
#define ABS(x) x > 0 ? x : -x

void main() {
	int arr[5], max = -1;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		arr[i] = ABS(arr[i]);
		if (arr[i] > max) { max = arr[i]; }
	}
	printf("%d\n", max);
}

#endif