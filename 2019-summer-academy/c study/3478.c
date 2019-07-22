#include "test.h"
#if (PNUM == 3478)
//소문자 대문자 변환
#include <stdio.h>

int main()
{
	char c;
	scanf("%c", &c);

	if (96 < c && c < 123) {
		c -= 32;
	}
	else if (64 < c && c < 91) {
		c += 32;
	}

	printf("%c", c);

	return 0;
}
#endif