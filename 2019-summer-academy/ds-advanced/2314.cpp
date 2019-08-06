#if 0

// 암소 라인업 문제

#include <iostream>

#define STEP 1
#define MAX 200000

using namespace std;

struct cow
{
    int x, id;
};

cow cows[50001], temp[50001];
int new_id[MAX];
int id_chk[MAX];
int id_cnt, n;

int get_newid(int id) {
    int key = id % MAX;
    for (int i = 0; i < MAX; i++) {
        if (new_id[key] == 0) {
            new_id[key] = id;
            id_cnt++;
            return key;
        }
        if (new_id[key] == id) {
            return key;
        }
        key = (key + STEP) % MAX;
    }
    return -1;
}

void msort(int s, int e) {
    int i, j, k, m;
    if (s >= e) return;
    m = (s + e) / 2;
    msort(s, m);
    msort(m + 1, e);
    i = s;
    j = m + 1;
    k = s;
    while (i <= m && j <= e) {
        if (cows[i].x < cows[j].x) temp[k++] = cows[i++];
        else temp[k++] = cows[j++];
    }
    while (i <= m) temp[k++] = cows[i++];
    while (j <= e) temp[k++] = cows[j++];
    for (i = s; i <= e; i++) cows[i] = temp[i];
}

int solve() {
    int s, e, type = 0, min = 0x7FFFFFFF, dist;
    for (s = 0, e = 0; s < n; s++) {
        if (!id_chk[cows[s].id]++) type++;

        while (type == id_cnt) {
            dist = cows[s].x - cows[e].x;
            if (dist < min) min = dist;
            if (!--id_chk[cows[e].id]) type--;
            e++;
        }
    }

    return min;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].id;
        cows[i].id = get_newid(cows[i].id);
    }

    msort(0, n - 1);
    cout << solve();

    return 0;
}

#endif
