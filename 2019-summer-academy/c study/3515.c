#include "test.h"
#if (PNUM == 3515)
//합이 가장큰 행, 열
#include <stdio.h>

void main() {
	int a[4][5] = { { 3, -5, 12, 3, -21 },{ -2, 11, 2, -7, -11 }, { 21, -21, -35, -93, -11 },{ 9, 14, 39, -98, -1 } };
	int maxRawIdx = 0, maxColIdx = 0;
	int max = 0x80000000;
	int cur = 0;

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
}
#endif