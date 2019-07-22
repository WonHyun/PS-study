#if 0

//프린터 문제 c버전

#include <stdio.h>
#define MAX (100*100)

int N, M;
int cnt[10]; //우선순위별 문서의 개수

typedef struct {
    int ord, pos;
}QUEUE;

QUEUE queue[MAX];
int rp, wp;
int In_Queue(int ord, int pos) {
    if (wp == MAX) return -1;
    queue[wp].ord = ord;
    queue[wp].pos = pos;
    wp++;
    return 1;
}
int Out_Queue(QUEUE* p) {
    if (rp == wp) return -1;
    *p = queue[rp];
    rp++;
    return 1;
}

int solve() {
    int sol = 0;
    QUEUE q;

    for (int i = 9; i > 0; i--) {
        while (cnt[i]) {
            Out_Queue(&q);
            if (q.ord == i) {
                cnt[i]--;
                sol++;
                if (q.pos == M) return sol;
            }
            else In_Queue(q.ord, q.pos);
        }
    }

    return sol;
}

int main() {
    int t;

    scanf("%d",&t);
    for (int k = 0; k < t; k++) {
        int ord, ret;
        for (int i = 0; i < 10; i++) cnt[i] = 0;

        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf("%d", &ord);
            cnt[ord]++;
            In_Queue(ord, i);
        }
        ret = solve();
        printf("%d\n", ret);
    }

    return 0;
}

#endif
