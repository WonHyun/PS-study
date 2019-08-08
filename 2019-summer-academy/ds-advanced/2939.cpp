#if 0

// 블루레이 문제

#include <cstdio>

int tree[600001]; // (m + n) * 3
int pos[100001]; // cd position

int t, n, m, cd;

void init() {
    for (int i = 1; i <= 600000; i++) tree[i] = 0;
    for (int i = 1; i < 100001; i++) pos[i] = 0;
}

void update(int node, int s, int e, int idx, int data) {
    int m;
    if (s == e) {
        tree[node] = data;
        return;
    }
    m = (s + e) / 2;
    if (idx <= m) {
        update(node * 2, s, m, idx, data);
    }
    else {
        update(node * 2 + 1, m + 1, e, idx, data);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int s, int e, int qs, int qe) {
    int m, sum = 0;
    if (s > qe || e < qs) return 0;
    if (s >= qs && e <= qe) return tree[node];
    m = (s + e) / 2;
    sum += query(node * 2, s, m, qs, qe);
    sum += query(node * 2 + 1, m + 1, e, qs, qe);
    return sum;
}

int main() {
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        init();
        scanf("%d %d", &n, &m);
        for (int j = 1; j <= n; j++) {
            pos[j] = m + j; // record cd position
            update(1, 1, n + m, m + j, 1);
        }

        for (int j = 0; j < m; j++) {
            scanf("%d", &cd);
            printf("%d ", query(1, 1, n + m, 1, pos[cd] - 1));
            update(1, 1, n + m, pos[cd], 0);
            update(1, 1, n + m, m - j, 1);
            pos[cd] = m - j;
        }
        printf("\n");
    }


    return 0;
}

#endif
