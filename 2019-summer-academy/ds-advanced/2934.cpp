#if 0

// 구간의 합 구하기

#include <iostream>

using namespace std;

int tree[150000];
int n, q;

void update(int node, int s, int e, int idx, int data) {
    int m;
    if (s == e) {
        tree[node] += data;
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
    if (e <= qe && s >= qs) return tree[node];

    m = (s + e) / 2;

    sum += query(node * 2, s, m, qs, qe);
    sum += query(node * 2 + 1, m + 1, e, qs, qe);

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int qs, qe, idx, data, add;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> data;
        update(1, 1, n, i, data);
    }

    for (int i = 1; i <= q; i++) {
        cin >> qs >> qe >> idx >> add;
        cout << query(1, 1, n, qs, qe) << endl;
        update(1, 1, n, idx, add);
    }

    return 0;
}

#endif

#if 0

// 입출력 time limit 때문에 c언어 버전도 추가

#include <cstdio>

int tree[150000];
int n, q;

void update(int node, int s, int e, int idx, int data) {
    int m;
    if (s == e) {
        tree[node] += data;
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
    if (e <= qe && s >= qs) return tree[node];

    m = (s + e) / 2;

    sum += query(node * 2, s, m, qs, qe);
    sum += query(node * 2 + 1, m + 1, e, qs, qe);

    return sum;
}

int main() {
    int qs, qe, idx, data, add;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &data);
        update(1, 1, n, i, data);
    }

    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d %d", &qs, &qe, &idx, &add);
        printf("%d\n", query(1, 1, n, qs, qe));
        update(1, 1, n, idx, add);
    }

    return 0;
}

#endif
