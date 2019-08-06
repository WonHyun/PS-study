#if 0

// 힙 소트 구현
// 부모노드는 현재 노드의 / 2
// 시작노드는 1부터
// L = P * 2, R = P * 2 + 1

#include <cstdio>

#define MAX_HEAP 30000

int N;
int heap[MAX_HEAP + 1];
int lastnode = 0;

int Heap_Push(int d) {
    int p, c, temp;
    if (lastnode == MAX_HEAP) return 0; //full
    heap[++lastnode] = d; //마지막 노드에 추가
    c = lastnode; //자식
    p = c / 2; //부모
    while (p > 0) { //부모가 최상위 노드이내일 동안 반복
        if (heap[p] < heap[c]) { //자식이 더 크면 교환
            temp = heap[p];
            heap[p] = heap[c];
            heap[c] = temp;
            c = p;
            p = c / 2;
        }
        else break;//더이상 교환할 필요없으면 종료
    }
    return 1;
}



int Heap_Pop(int* d)
{
    int p, l, r, c, temp;
    if (lastnode == 0) return 0;
    *d = heap[1];

    heap[1] = heap[lastnode--];
    p = 1; l = 2; r = 3;

    while (l <= lastnode) {
        if (l == lastnode) c = l; // 자식이 1개인 경우 L을 본다
        else if (heap[l] > heap[r]) c = l; //자식이 둘인 경우 후계자 결정
        else c = r;

        if (heap[p] < heap[c]) { // 자식이 큰 경우 교환
            temp = heap[c];
            heap[c] = heap[p];
            heap[p] = temp;
            p = c; l = p * 2; r = l + 1;
        }
        else break;
    }
    return 1;
}

int main(void)
{
    int i, d;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &d);
        Heap_Push(d);
    }

    for (i = N; i >= 1; i--)
    {
        Heap_Pop(&d);
        heap[i] = d;
    }

    for (i = 1; i <= N; i++)
    {
        printf("%d ", heap[i]);
    }

    return 0;
}
#endif
