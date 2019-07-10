#include "test.h"
//#if (PNUM == 3411)
#if 1
#include <stdio.h>

int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
int* p = a[0];

void main(void)
{
    printf("%d\n", a[2][3]);

    //p 변수만 이용하여 배열내의 숫자 12을 인쇄하시오

    printf("%d\n", p[11]);

}
#endif
