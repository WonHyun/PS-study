#include "../test-algo.h"
#if (PNUM == 1332)

// 농장 탈출 문제 

using namespace std;

int n, ans;
int w[20];

int valid(int a, int b) {
    int ca = a, cb = b;
    while (ca != 0 && cb != 0) {
        int cur = ca % 10;
        cur += cb % 10;
        if (cur > 9) return -1;
        ca /= 10;
        cb /= 10;
    }

    return a + b;
}

void dfs(int no, int sum, int count) {
    if (no >= n) {
        if (count > ans) ans = count;
        return;
    }

    int calSum = valid(sum, w[no]);
    if (calSum > 0) {
        dfs(no + 1, calSum, count + 1); // 해당 소를 선택 후 재귀
    }
    dfs(no + 1, sum, count); // 해당 소를 선택하지 않는 경우
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    dfs(0, 0, 0);

    cout << ans;

    return 0;
}

#endif
