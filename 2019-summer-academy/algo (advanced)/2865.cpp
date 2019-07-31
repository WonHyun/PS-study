#include "test-algo.h"
#if (PNUM == 2865)

// 건물세우기 문제

using namespace std;

int n, minCost;
int map[100][100]; // y축 : 건물번호, x축 : 부지번호
int chk[100]; // 한 건물이 선택한 부지는 다른 건물이 선택할 수 없다

void dfs(int no, int sum)
{
    if (sum > min) return;
    if (no >= n) {
        if (sum < minCost) minCost = sum;
        return;
    }
    //i를 부지 번호라고 생각하면 된다
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        chk[i]++;
        dfs(no + 1, sum + map[no][i]);
        chk[i]--;
    }
}

int main(void)
{
    minCost = 0x7FFFFFFF;
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    dfs(0, 0);

    cout << minCost;

    return 0;
}

#endif
