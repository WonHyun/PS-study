#include "test.h"
#if (PNUM == 3413)
#include <stdio.h> 

struct math
{
    int id;
    char name[20];
    int score;
};

void cheat(struct math* test);

void main(void)
{
    struct math final = { 1, "Kim", 50 };
    cheat(&final);
    printf("%d\n", final.score);
}

// 함수에서 score를 100으로 수정하는 코드를 작성하라 
// 단, -> 연산자는 사용할 수 없다 

void cheat(struct math* test)
{
    //test->score = 100;
    test[0].score = 100;
}
#endif
