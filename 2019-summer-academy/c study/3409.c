#include "test.h"
#if (PNUM == 3409)
//2차원 배열의 리턴
#include <stdio.h>

//int* func(void)
//{
//    static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//    return a;
//}
//
//void main(void)
//{
//    printf("%d\n", func()[6]);
//}


int (*func(void))[4]
{
    static int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    return a;
}

void main(void)
{
    printf("%d\n", func()[1][2]);
}

#endif
