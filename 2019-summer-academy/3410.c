#include "test.h"
#if (PNUM == 3410)
//배열의 인덱스

#include <stdio.h>

int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
int* b[3] = { a[2], a[1], a[0] };

void main(void)
{
    printf("%d\n", a[2][3]);

    //b를 이용하여 배열내의 숫자 12을 인쇄하시오

    printf("%d\n", b[0][3]);
}

#endif
