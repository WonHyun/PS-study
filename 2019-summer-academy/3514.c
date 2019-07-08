#include "test.h"
#if (PNUM == 3514)
//알파벳 빈도
#include <stdio.h>

int frequency[26];

void main(void)
{
	char input[31];
	int max = 0, maxIdx = 0;
	scanf("%s", input);
	for (int i = 0; input[i] != '\0'; i++) {
		frequency[input[i] - 97]++;
	}
	for (int i = 0; i < sizeof(frequency) / sizeof(frequency[0]); i++) {
		if (max < frequency[i]) { max = frequency[i]; maxIdx = i; }
	}
	//max를 빼고 이거도 가능
	//if (frequency[maxIdx] < frequency[i]) { maxIdx = i; }
	printf("%c", maxIdx + 97);
	//97대신에 'a' 써도 됨
}
#endif
