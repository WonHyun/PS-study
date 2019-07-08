#include "test.h"
#if (PNUM == 3517)
//구조체 정렬
#include <stdio.h>

struct student
{
	int id;
	int score;
};

struct student sarr[5001];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		struct student s; s.id = i + 1;
		scanf("%d", &s.score);
	}
	struct student temp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (sarr[i].score < sarr[j].score) {
				temp = sarr[i];
				sarr[i] = sarr[j];
				sarr[j] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("%d ", sarr[i].id);
	}

	return 0;
}
#endif