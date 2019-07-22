#include "test.h"
#if (PNUM == 10000)
//최댓값 행, 열 번호
#include <stdio.h>

int a[1000][1000];

void main() {
	int maxRawIdx = 0, maxColIdx = 0;
	int max = 0x80000000;
	int cur = 0;
	int n;

	scanf("%d", &n);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%d", &a[y][x]);
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cur += a[y][x];
		}
		if (cur > max) { max = cur; maxRawIdx = y; }
		cur = 0;
	}

	max = 0x80000000;

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 4; y++) {
			cur += a[y][x];
		}
		if (cur > max) { max = cur; maxColIdx = x; }
		cur = 0;
	}

	printf("%d %d", ++maxRawIdx, ++maxColIdx);
	//행, 열의 합의 값을 배열로 다뤄서 풀어도 됨
}
#endif