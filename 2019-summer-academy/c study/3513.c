#include "test.h"
#if (PNUM == 3513)
//성적처리 배열버전
#include <stdio.h>

char lookup[] = "FFFFFFDCBAA";

int calGrade(int score) {
	if (score < 0 || score > 100) return 'X';
	return lookup[score / 10];
}

void main(void)
{
	int score;
	scanf("%d", &score);
	printf("%c", calGrade(score));
}
#endif