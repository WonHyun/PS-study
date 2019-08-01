#include "test-algo.h"
#if (PNUM == 2450)

// 퍼킷 문제

using namespace std;

struct food
{
    int s, b;
};

int n, mini;

food foods[11];
food comb[11];
food zero;

void dfs(int no)
{
    if (no >= n) {
        int sour = 1, bitter = 0, diff, sum = 0;
        for (int i = 0; i < n; i++) {
            if (comb[i].s) sour *= comb[i].s;
            if (comb[i].b) bitter += comb[i].b;
        }

        diff = sour - bitter > 0 ? sour - bitter : bitter - sour;

        for (int i = 0; i < n; i++) sum += comb[i].s; // 0개 선택 조합일 경우 0
        if (sum && diff < mini) mini = diff;
        return;
    }
    comb[no] = foods[no];
    dfs(no + 1);
    comb[no] = zero;
    dfs(no + 1);
}

int main(void)
{
    mini = 0x7FFFFFFF;
    cin >> n;

    for (int i = 0; i < n; i++) {
        food cur;
        cin >> cur.s >> cur.b;
        foods[i] = cur;
    }

    dfs(0);

    cout << mini;

    return 0;
}

#endif
