#include "test.h"
#if (PNUM == 3493)
//삼각형
#include <stdio.h>

void Draw_Star2(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	Draw_Star2(n);
	return 0;
}
#endif