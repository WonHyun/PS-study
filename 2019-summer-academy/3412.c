#include "test.h"
#if (PNUM == 3412)
#include <stdio.h>

// func 함수의 parameter를 완성하라 
void func(int *p)
{
    // main의 a[2]를 50으로 만드는 코드를 설계하라
    p[2] = 50;
}

void main(void)
{
    int a[4] = { 10,20,30,40 };

    printf("%d\n", a[2]);
    func(&a);
    printf("%d\n", a[2]);
}
#endif
