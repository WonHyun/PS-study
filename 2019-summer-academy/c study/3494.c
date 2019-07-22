#include "test.h"
#if (PNUM == 3494)
//피라미드
#include <stdio.h>

void Draw_Star3(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	Draw_Star3(n);
	return 0;
}
#endif