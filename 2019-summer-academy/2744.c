#include "test.h"
#if (PNUM == 2744)
//문자열 연결
#include <stdio.h>

void str_add(char* d, const char* s)
{
	while (*d != '\0') { d++; } // while (*d++); d--;
	while (*s != '\0') { *d++ = *s++; } // while (*d++ = *s++);
}

void main(void)
{
	char a[15] = "Willtek";
	char b[15] = " Corp.";

	str_add(a, b);

	printf("%s\n", a);
}

#endif