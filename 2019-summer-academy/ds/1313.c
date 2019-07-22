//ds test4
#if 0
#include <stdio.h>

#define STEP   2
#define HASH   5  

int Hash[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int Insert(int d)
{
    // 코드설계
    int key = d % HASH;
    int i;

    for (i = 0; i < 10; i += STEP) {
        if (Hash[key] == -1) {
            Hash[key] = d;
            return key;
        }
        key = (key + STEP) % 10;
    }
    return -1;
}

int Delete(int d)
{
    // 코드설계
    int i;
    int key = d % HASH;
    int idx = -1;

    for (i = 0; i < 10; i += STEP) {
        if (Hash[key] == d) {
            idx = i;
            break;
        }
        key = (key + STEP) % 10;
    }

    if (idx == -1) return -1;
    Hash[idx] = -1;
    return idx;
}

/********************************************************************************/
/* 이 부분은 설계한 코드의 오류를 확인하기 위한 테스트 코드임 수정금지   */
/********************************************************************************/

int main(void)
{
    int i;
    int r;

    int oper[] = { 1, 1, 1, 1, 1, 1, 1,  1,  1,  1,   1, 0, 0,  1,  1 };
    int hash[] = { 2, 0, 5, 4, 7, 9, 9,  8,  15, 17, 21, 2, 31, 18, 50 };
    int res[] = { 2, 0, 4, 6, 8, 1, -1, 3,   5, 7,  -1, 2, -1, 2,  -1 };

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++)
    {
        printf("TEST VECTOR [%d]\n", i);

        if (oper[i] == 1)
        {
            r = Insert(hash[i]);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, Your return=> %d\n", res[i], r);
                return 0;
            }

            else
            {
                if ((r != -1) && (hash[i] != Hash[r]))
                {
                    printf(">>>>Fail: Expected HASH data => %d, Your HASH data => %d\n", hash[i], Hash[r]);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d, value => %d\n", r, Hash[r]);
                    else printf("return => %d\n", r);
                }
            }
        }

        else
        {
            r = Delete(hash[i]);

            if (res[i] != r)
            {
                printf(">>>>Fail: Expected return => %d, Your return=> %d\n", res[i], r);
                return 0;
            }

            else
            {
                if ((r != -1) && (Hash[r] != -1))
                {
                    printf(">>>>Fail: Expected HASH data => %d, Your HASH data => %d\n", hash[i], Hash[r]);
                    return 0;
                }

                else
                {
                    if (r != -1) printf("return => %d\n", r);
                    else printf("return => %d\n", r);
                }
            }
        }
    }

    return 1;
}
#endif
