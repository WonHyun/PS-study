#if 0

//c버전 수식 계산기

#include <stdio.h>
#define MAX 30

int sp = MAX;
int stack[MAX];

int a[MAX];
char op[MAX];

int push(int data) {
    if (sp == 0) return -1;
    sp--;
    stack[sp] = data;
    return 1;
}

int pop(int* p) {
    if (sp == MAX) return -1;
    *p = stack[sp];
    sp++;
    return 1;
}

int main() {
    int i, N, data, sum = 0;

    //파일에서 불러오기
    //freopen("input.txt", "r", stdin);

    scanf("%d", &N);
    scanf("%d", &a[0]);

    for (i = 1; i < N; i++) {
        scanf(" %c %d", &op[i], &a[i]);
    }

    push(a[0]);

    for (i = 1; i < N; i++) {
        if (op[i] == '+') {
            push(a[i]);
        }
        else if (op[i] == '-') {
            push(-a[i]);
        }
        else if (op[i] == '*') {
            pop(&data);
            push(data * a[i]);
        }
        else if (op[i] == '/') {
            pop(&data);
            push(data / a[i]);
        }
    }

    while (pop(&data) != -1) {
        sum += data;
    }

    printf("%d", sum);

    return 0;
}

#endif
