#include "test.h"
#if (PNUM == 3408)
//2차원 배열의 전달
#include <stdio.h>

void draw_pixel(int y, int x, int value, int (*p)[3])
{
    p[y][x] = value;
}

void main(void)
{
    int a[2][3] = { 1,2,3,4,5,6 };

    printf("%d\n", a[1][2]);
    draw_pixel(1, 2, 10, a);
    printf("%d\n", a[1][2]);
}

#endif
