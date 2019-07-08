#include "test.h"
#if (PNUM == 3488)
//f~z사이의 문자 찾기
#include <stdio.h>
int judge(char input) {
	return 101 < input && input < 123 ? 1 : 0;
}
int main() {
	char input;
	scanf("%c", &input);
	printf("%s", judge(input) ? "YES" : "NO");
	return 0;
}
#endif