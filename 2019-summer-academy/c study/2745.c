#include "test.h"
#if (PNUM == 2745)
//문자열 비교
#include <stdio.h>

int str_comp(const char* a, const char* b)
{
	
	//do {
	//	if (*a < *b) return -1;
	//	if (*a > *b) return 1;
	//	b++;
	//} while (*a++);
	//return 0;
	
	while (*a != '\0' || *b != '\0') {
		if (*a == *b) { a++; b++; continue; }
		else if (*a > * b) { return 1; }
		else { return -1; }
	}

	if (*a > * b) { return 1; }
	if (*a < *b) { return -1; }

	return 0;
}

void main(void)
{
	printf("%d\n", str_comp("ABC", "BC"));
	printf("%d\n", str_comp("ABC", "AC"));
	printf("%d\n", str_comp("ABC", "AB"));
	printf("%d\n", str_comp("abc", "ABC"));
	printf("%d\n", str_comp("ab", " "));
	printf("%d\n", str_comp("A", "AB"));
}
#endif