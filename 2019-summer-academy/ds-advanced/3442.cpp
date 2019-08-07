#if 0

// 스위치 문제

#include <cstdio>

int n;
int m;

int tree[262144];

void input_data(void) {
    scanf("%d %d", &n, &m);
}


void toggleSwitch(int node, int s, int e, int idx) {
    int m;
    if (s == e) {
        tree[node] = !tree[node]; // switch toggle
        return;
    }
    m = (s + e) / 2;

    if (idx <= m) {
        toggleSwitch(node * 2, s, m, idx);
    }
    else {
        toggleSwitch(node * 2 + 1, m + 1, e, idx);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // sum of switches on
}

int query(int node, int s, int e, int qs, int qe) {
    int m, sum = 0;
    if (s > qe || e < qs) return 0;
    if (s >= qs && e <= qe) return tree[node]; // if switch on ? 1 off ? 0
    m = (s + e) / 2;
    sum += query(node * 2, s, m, qs, qe);
    sum += query(node * 2 + 1, m + 1, e, qs, qe);
    return sum;
}

void solve(void) {
    int o, qs, qe, result;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &qs, &qe);
        if (o) {
            printf("%d\n", query(1, 1, n, qs, qe));
        }
        else {
            for (int j = qs; j <= qe; j++) { // toggle switches in range
                toggleSwitch(1, 1, n, j);
            }
        }
    }
}

int main(void) {
    input_data();
    solve();
    return 0;
}

#endif
