#include "test.h"
#if (PNUM == 3521)
//한줄에 한자씩
#include <stdio.h>

void main(void)
{
	char a[11];
	scanf("%s", a);
	for (int i = 0; a[i] != '\0'; i++) {
		printf("%c\n", a[i]);
	}
}
#endif