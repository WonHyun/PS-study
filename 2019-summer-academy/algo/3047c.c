#if 0

//c버전 조깅문제

#include <stdio.h>

#define MAX 100001

int sp = 0;
int a[MAX];
int stack[MAX];

int main() {
    int N, cur, temp, answer = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %*d %d", &a[i]); //*은 무시함
    }

    for (int i = 0; i < N; i++) {
        while (sp > 0) {
            if (stack[sp] > a[i]) { sp--; }
            else { break; }
        }
        stack[++sp] = a[i];
    }

    printf("%d", answer);

    return 0;
}

#endif
