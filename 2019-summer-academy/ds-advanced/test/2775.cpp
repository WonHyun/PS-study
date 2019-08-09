#if 0

// 나무 자르기 문제

#include <iostream>

using namespace std;

int n, m;

int tree[1000001];

long long check(int mid) {
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (tree[i] > mid) sum += tree[i] - mid;
    }

    return sum;
}

int main() {
    int s = 0, e = 0, mid, sol = 0;
    long long cur;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        if (e < tree[i]) e = tree[i];
    }

    while (s <= e) {
        mid = (s + e) / 2;
        cur = check(mid);
        if (cur >= m) {
            s = mid + 1;
            sol = mid;
        }
        else {
            e = mid - 1;
        }
    }

    cout << sol;

    return 0;
}

#endif
