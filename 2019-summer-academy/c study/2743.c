#include "test.h"
#if (PNUM == 2473)
//문자열길이 측정
#include <stdio.h>

unsigned int str_lenth(const char* d)
{
	unsigned int count = 0;
	while (*d++ != '\0') { //while(*d++)
		count++;
	}

	return count;
}

void main(void)
{
	char a[] = "Willtek";

	printf("%d\n", sizeof(a));
	printf("%d\n", str_lenth(a));
}
#endif
