#include "test.h"
#if (PNUM == 10001)
//가위바위보
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char choose[3][5] = { "가위", "바위", "보" };
	char result[3][5] = { "비김", "승리", "패배" };
	int resultNum;
	int input;
	int comChoice;
	srand((unsigned int)time(NULL));

	while (1) {
		printf("가위(0), 바위(1), 보(2)를 입력하시오.\n");
		scanf("%d", &input);
		if (input > 2 || input < 0) break;
		comChoice = rand() % 3;
		printf("You = %s PC = %s\n", choose[input], choose[comChoice]);
		if (input == comChoice) {
			resultNum = 0;
		}
		else if ((input + 1) % 3 == comChoice) {
			resultNum = 2;
		}
		else {
			resultNum = 1;
		}
		printf("%s\n", result[resultNum]);
	}

	return 0;
}
#endif