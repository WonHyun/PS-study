#if 0

// 구간의 최대값 구하기

#include <cstdio>

int tree[150000];
int n, q;

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
    tree[node] = tree[node * 2] > tree[node * 2 + 1] ? tree[node * 2] : tree[node * 2 + 1];
}

int query(int node, int s, int e, int qs, int qe) {
    int m, sum = 0, l, r;
    if (s > qe || e < qs) return 0;
    if (e <= qe && s >= qs) return tree[node];

    m = (s + e) / 2;

    l = query(node * 2, s, m, qs, qe);
    r = query(node * 2 + 1, m + 1, e, qs, qe);

    return l > r ? l : r;
}

int main() {
    int qs, qe, idx, data, add;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &data);
        update(1, 1, n, i, data);
    }

    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qs, &qe);
        printf("%d\n", query(1, 1, n, qs, qe));
    }

    return 0;
}

#endif
