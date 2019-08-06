#if 0

// �� ��Ʈ ����
// �θ���� ���� ����� / 2
// ���۳��� 1����
// L = P * 2, R = P * 2 + 1

#include <cstdio>

#define MAX_HEAP 30000

int N;
int heap[MAX_HEAP + 1];
int lastnode = 0;

int Heap_Push(int d) {
    int p, c, temp;
    if (lastnode == MAX_HEAP) return 0; //full
    heap[++lastnode] = d; //������ ��忡 �߰�
    c = lastnode; //�ڽ�
    p = c / 2; //�θ�
    while (p > 0) { //�θ� �ֻ��� ����̳��� ���� �ݺ�
        if (heap[p] < heap[c]) { //�ڽ��� �� ũ�� ��ȯ
            temp = heap[p];
            heap[p] = heap[c];
            heap[c] = temp;
            c = p;
            p = c / 2;
        }
        else break;//���̻� ��ȯ�� �ʿ������ ����
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
        if (l == lastnode) c = l; // �ڽ��� 1���� ��� L�� ����
        else if (heap[l] > heap[r]) c = l; //�ڽ��� ���� ��� �İ��� ����
        else c = r;

        if (heap[p] < heap[c]) { // �ڽ��� ū ��� ��ȯ
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
