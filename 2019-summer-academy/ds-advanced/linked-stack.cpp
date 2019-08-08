#if 0

// stack 구현

#include <cstdio>
#include <cstdlib>

int n, st_size;

struct stack
{
    int data;
    struct stack* prev;
};

stack* sp;

int push(int d) {
    stack *s = (stack *)calloc(1, sizeof(stack));
    s->data = d;
    s->prev = sp;
    sp = s;
    st_size++;
    return 1;
}
int pop(stack *d) {
    stack* temp = sp;
    if (sp == NULL) return 0;
    *d = *sp;
    sp = sp->prev;
    free(temp);
    st_size--;
    return 1;
}

int main() {
    stack temp;
    int cmd, data;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 0:
            if (pop(&temp)) printf("%d\n", temp.data);
            else printf("E\n");
            break;
        case 1:
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("%d\n", st_size);
            break;
        default:
            break;
        }
    }

    return 0;
}

#endif
