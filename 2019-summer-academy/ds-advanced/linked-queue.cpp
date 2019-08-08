#if 0

#include <cstdio>
#include <malloc.h>

struct st
{
    int id;
    struct st* rp; // next
    struct st* wp; // prev
};

struct st HEAD = { 0,NULL, NULL };
struct st TAIL = { 0,NULL, NULL };

struct st* QUEUE(int d)
{
    // 코드설계
    struct st* s = (st*)calloc(1, sizeof(struct st));
    s->id = d;
    s->rp = &TAIL;
    s->wp = TAIL.wp;
    TAIL.wp = s;
    s->wp->rp = s;
    return s;
}

int DEQUEUE(int* p)
{
    // 코드설계
    struct st* temp = HEAD.rp; // 첫 노드주소 백업
    if (HEAD.rp == &TAIL) return -1; // queue가 빈 경우
    *p = temp->id;
    HEAD.rp = temp->rp; // 삭제할 노드의 next를 head의 next로
    temp->rp->wp = temp->wp; // 삭제할 노드의 prev를 다음 노드의 prev로
    free(temp);
    return 0;
}

int main(void)
{
    int i;
    int d;

    struct st* r, * t;
    int p[1];
    int oper[] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,  1, 1, 1, 0, 0, 1, 1,  0, 0, 0,  0 };
    int que[] = { 1, 3, 5, 7, 9,  1, 3, 5, 7, 9, 0,  2, 4, 6, 2, 4, 8, 10, 6, 8, 10, 0 };
    int ans[] = { 1, 3, 5, 7, 9,  0, 0, 0, 0, 0, -1, 2, 4, 6, 0, 0, 8, 10, 0, 0, 0,  -1 };

    HEAD.rp = &TAIL;
    TAIL.wp = &HEAD;

    for (i = 0; i < (sizeof(oper) / sizeof(oper[0])); i++) {
        printf("\nTEST VECTOR [%d]\n", i);

        if (oper[i] == 1) {
            r = QUEUE(que[i]);
            t = HEAD.rp;

            while (t->rp != NULL) {
                printf("=> [%d]", t->id);
                t = t->rp;
            }

            printf("\n");
            t = TAIL.wp;

            while (t->wp != NULL) {
                printf("=> [%d]", t->id);
                t = t->wp;
            }

            printf("\n");

            if (r == NULL) {
                printf(">>>>틀림: 리턴된구조체의주소가NULL 포인터임\n");
                return 0;
            }

            if (r->id != ans[i]) {
                printf(">>>>틀림: 리턴된구조체주소의id 예상값=> %d, 실제리턴된구조체의id 값=> %d\n", ans[i], r->id);
                return 0;
            }

            if (TAIL.wp != r) {
                printf(">>>>틀림: TAIL측wp 링크오류(TAIL의wp가리턴된자료주소가아님)\n");
                return 0;
            }

            if (r->rp != &TAIL) {
                printf(">>>>틀림: 리턴된자료의rp가TAIL의주소가아님)\n");
                return 0;
            }

            t = &HEAD;

            for (;;) {
                if (t->rp == &TAIL) break;
                else t = t->rp;
            }

            if ((t != r) || (t->id != r->id)) {
                printf(">>>>틀림: HEAD측으로부터찾은TAIL 바로앞에있어야하는구조체주소와리턴된구조체주소가다름\n");
                return 0;
            }
            printf("OK\n");
        }
        else {
            d = DEQUEUE(p);
            t = HEAD.rp;

            while (t->rp != NULL) {
                printf("=> [%d]", t->id);
                t = t->rp;
            }

            printf("\n");
            t = TAIL.wp;

            while (t->wp != NULL) {
                printf("=> [%d]", t->id);
                t = t->wp;
            }

            printf("\n");

            if (d != ans[i]) {
                printf(">>>>틀림: 예상리턴값= %d, 실제리턴값= %d\n", ans[i], d);
                return 0;
            }

            if (d != -1) {
                if (*p != que[i]) {
                    printf(">>>>틀림: 큐에서꺼내서p 주소에들어있는데이터의예상값=> %d, 실제p 주소에들어있는값=> %d\n", que[i], *p);
                    return 0;
                }

                t = &HEAD;

                for (;;) {
                    if (t->rp == &TAIL) break;
                    else t = t->rp;
                }

                t = &TAIL;

                for (;;) {
                    if (t->wp == &HEAD) break;
                    else t = t->wp;
                }
            }
            printf("OK\n");
        }
    }
    return 1;
}

#endif
