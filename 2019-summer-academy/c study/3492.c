#include "test.h"
#if (PNUM == 3492)
//정사각형
#include <stdio.h>

void Draw_Star(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	Draw_Star(n);
	return 0;
}
#endif