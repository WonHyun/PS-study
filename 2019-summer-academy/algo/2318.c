#if 0

//카드 건네기 c버전

#include <stdio.h>
#define MAX (100*20)

int N;
int queue[MAX];
int rp, wp;
int rec[110];

int In_Queue(int data) {
    if (wp == MAX) return -1;
    queue[wp] = data;
    wp++;
    return 1;
}

int Out_Queue(int *p) {
    if (rp == wp) return -1;
    *p = queue[rp];
    rp++;
    return 1;
}

int main() {
    int i, j, cnt = 0, card;
    scanf("%d", &N);
    rp = wp = 0;
    for (i = 1; i <= N; i++) {
        In_Queue(i);
    }

    for (i = 0; i < N - 1; i++) {
        cnt = queue[wp - 1] / 2;
        for (j = 0; j < cnt; j++) {
            Out_Queue(&card);
            In_Queue(card);
        }
        Out_Queue(&card);
        rec[i] = card;
    }

    Out_Queue(&card);
    rec[i] = card;

    for (i = 0; i < N; i++) printf("%d ", rec[i]);

    return 0;
}

#endif
