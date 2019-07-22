#include "test.h"
#if (PNUM == 2748)
//문자열 swap
#include <stdio.h>

void Swap(char *p, char *q)
{
    char* temp = *p;
    *p = *q;
    *q = temp;
}

void main()
{
    char* a = "hello";
    char* b = "hi";

    printf("Before : %s, %s\n", a, b);
    printf("Before : %p, %p\n", &(*a), &(*b));

    Swap(&a, &b);

    printf("After : %s, %s\n", a, b);
    printf("After : %p, %p\n", &(*a), &(*b));
}
#endif
