#include "test.h"
#if (PNUM == 3481)
//주민번호로 조편성하기
#include <stdio.h>

int CreateGroup(int num) {
	return (num % 4) + 1;
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", CreateGroup(num));

	return 0;
}
#endif