#if 0

// 최소 비용 포장 문제
// 힙정렬 이용

#include <iostream>
#define MAX_HEAP 5001

using namespace std;

int N;
int heap[MAX_HEAP + 1];
int lastnode = 0;

int Heap_Push(int d) {
    int p, c, temp;
    if (lastnode == MAX_HEAP) return 0; 
    heap[++lastnode] = d; 
    c = lastnode;
    p = c / 2; 
    while (p > 0) { 
        if (heap[p] > heap[c]) { 
            temp = heap[p];
            heap[p] = heap[c];
            heap[c] = temp;
            c = p;
            p = c / 2;
        }
        else break;
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
        if (l == lastnode) c = l; 
        else if (heap[l] < heap[r]) c = l; 
        else c = r;

        if (heap[p] > heap[c]) { 
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
    int n, ni, cost = 0, sum = 0, first, second;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ni;
        Heap_Push(ni);
    }

    while (lastnode > 1) { // lastnode == 1 : 모두 합쳐져서 1개의 포장이 남았을때
        Heap_Pop(&first);
        Heap_Pop(&second);

        sum = first + second; // 포장
        cost += sum; // 비용은 누적
        Heap_Push(sum); // 포장 후 다시 push
    }

    cout << cost;

    return 0;
}
#endif
