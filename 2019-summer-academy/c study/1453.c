#include "test.h"
#if (PNUM == 1453)
//test 1번 대소문자 변경
#include <stdio.h>

char Change_Case(char c) {
	if (96 < c && c < 123) {
		c -= 32;
	}
	else if (64 < c && c < 91) {
		c += 32;
	}
	return c;
}

int main(void)
{
	char a;
	scanf("%c", &a);
	printf("%c", Change_Case(a));
	return 0;
}
#endif