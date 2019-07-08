#include "test.h"
#if (PNUM == 3511)
//성적처리
#include <stdio.h>
char Grade(int score) {
	if (score < 0 || score > 100) return 'X';
	switch (score / 10)
	{
	case 6:
		return 'D';
	case 7:
		return 'C';
	case 8:
		return 'B';
	case 9:
	case 10:
		return 'A';
	default:
		return 'F';
	}
}
int main() {
	int score;
	scanf("%d", &score);
	printf("%c", Grade(score));
	return 0;
}
#endif