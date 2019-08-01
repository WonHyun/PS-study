#include "test-algo.h"
#if (PNUM == 2373)

// sumsets 문제
// 2의 제곱수로 k만드는 경우의 수 문제

using namespace std;

int k, cnt;
int a[7] = {1, 2, 4, 8, 16, 32, 64};

void dfs(int start, int sum) {
    if (sum > k) return;
    if (sum == k) {
        cnt++;
        return;
    }
    for (int i = start; i < 7; i++) {
        dfs(i, sum + a[i]);
    }
}

int main(void)
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cnt = 0;
        cin >> k;
        dfs(0, 0);
        cout << cnt << endl;
    }

    return 0;
}

#endif
