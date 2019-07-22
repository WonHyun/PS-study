//ds test2
#if 0

#include <stdio.h>

int STACK[4];
int SP = 3;

int PUSH(int d)
{
    // 코드설계
    if (SP == -1) return 0xFF;
    STACK[SP--] = d;
    return SP;
}

int POP(int* p)
{
    // 코드설계
    if (SP == 3) return 0xFF;
    *p = STACK[++SP];
    return SP;
}

// 이부분은설계한코드의오류를확인하기위한테스트코드임수정금지 

int main(void)
{
    int i;
    int r;
    int d;

    int oper[] = { 1, 1, 1, 1, 1,    0, 0, 0, 0, 0,    1, 1, 1, 0, 0, 1, 1,  0 };
    int stk[] = { 1, 3, 5, 7, 9,     7, 5, 3, 1, 0,    2, 4, 6, 6, 4, 8, 10, 10 };
    int res[] = { 2, 1, 0, -1, 0xff, 0, 1, 2, 3, 0xFF, 2, 1, 0, 1, 2, 1, 0,  1 };

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        if (oper[i] == 1)
        {
            r = PUSH(stk[i]);

            if (r != res[i])
            {
                printf(">>>>Fail: Expected return => %d, Your return => %d\n", res[i], r);
                return 0;
            }

            if (r == 0xFF)
            {
                printf("return => 0x%.2X\n", r);
                continue;
            }

            if (STACK[SP + 1] != stk[i])
            {
                printf(">>>>Fail : Expected stack data => %d, Your stack data => %d\n", stk[i], STACK[SP + 1]);
                return 0;
            }

            printf("return => 0x%.2X\n", r);
            printf("PUSH => %d\n", STACK[SP + 1]);
        }

        else
        {
            r = POP(&d);

            if (r != res[i])
            {
                printf(">>>>Fail: Expected return => %d, Your return => %d\n", res[i], r);
                return 0;
            }

            if (r == 0xFF)
            {
                printf("return => 0x%.2X\n", r);
                continue;
            }

            if (d != stk[i])
            {
                printf(">>>>Fail: Expected POP data => %d, Your POP data => %d\n", stk[i], d);
                return 0;
            }

            printf("return => 0x%.2X\n", r);
            printf("POP => %d\n", d);
        }
    }

    return 1;
}
#endif
