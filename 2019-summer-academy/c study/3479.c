#include "test.h"
#if (PNUM == 3479)
//화폐변환
#include <stdio.h>

unsigned int convToHanwha(int n) {
	return n * 10.1;
}

int main() {

	int n;
	scanf("%d", &n);

	printf("%u", convToHanwha(n));

	return 0;
}

#endif