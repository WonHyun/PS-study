#include "test.h"
#if (PNUM == 10002)
//배열크기 출력 전처리
#include <stdio.h>
#define ARR_SIZE(x) { int size = sizeof(x)/sizeof(x[0]); printf("%d\n",size);}

int a[4] = { 1,2,3,4 };

void main() {
	ARR_SIZE(a);
}

#endif