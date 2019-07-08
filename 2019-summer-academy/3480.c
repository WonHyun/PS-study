#include "test.h"
#if (PNUM == 3480)
//float에 가장 가까운 정수 찾기
#include <stdio.h>

int FloatToInt(float input) {
	return input - (int)input > 0.5 ? input + 1 : input;
}

int main() {
	float input;
	scanf("%f", &input);
	printf("%d", FloatToInt(input));

	return 0;
}

#endif