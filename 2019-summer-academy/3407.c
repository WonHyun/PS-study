#include "test.h"
#if (PNUM == 3407)
//포인터 배열
#include <stdio.h>

int x[4] = { 1,2,3,4 };

void main()
{
    int* a[4] = { x + 3, x + 2, x + 1, x };

    printf("%d\n", x[2]);

    *a[1] = 30;

    printf("%d\n", x[2]);
}
#endif
