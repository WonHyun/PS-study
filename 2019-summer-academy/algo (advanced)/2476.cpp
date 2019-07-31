#include "test-algo.h"
#if (PNUM == 2476)

// N Queen 문제

using namespace std;

int n, cnt;

int map[11][11];
int chk[11]; // 퀸은 한 행 또는 열에 하나만 존재할 수 있다

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void queen(int y, int x, bool isSet) {
    int cx, cy, bit = -1;
    if (isSet) bit = 1;
    map[y][x] += bit;
    for (int dir = 0; dir < 8; dir++) {
        cx = x;
        cy = y;
        while (true) {
            cx += dx[dir];
            cy += dy[dir];
            if (cx < 0 || cx >= n || cy < 0 || cy >= n) break;
            map[cy][cx] += bit;
        }
    }
}

void dfs(int no)
{
    if (no >= n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!map[no][i] && !chk[i]) { // 요덕에 다음에 탐색해야 하는 수가 줄어듦
            chk[i]++;
            queen(no, i, true);
            dfs(no + 1);
            chk[i]--;
            queen(no, i, false);
        }
    }

    return;
}

int main(void)
{
    cin >> n;

    dfs(0);

    cout << cnt;

    return 0;
}

#endif
