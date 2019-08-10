#include "test-algo.h"
#if (PNUM == 1866)

using namespace std;

int n, m;

int map[13][13];
int chk[13];
int isCan; 

bool mark(int y, int color) {
    for (int x = 0; x < n; x++) {
        if (map[y][x] && chk[x + 1] == color) return true; // 해당 간선이 존재하고, 그 간선에 체크된 색상이 존재할 경우 불가능함을 알림
    }
    return false; // 해당 색으로 색칠이 가능함
}

void dfs (int no) {
    if (no >= n) { // 간선의 끝까지 모두 칠했다면
        isCan = true; // 색칠이 가능함을 알리고
        return; // 돌아간다.
    }

    for (int i = 0; i < m; i++) {
        if (mark(no, i + 1)) continue;
        chk[no + 1] = i + 1; // 해당 간선에 i+1 색을 칠했다는 것을 체크
        dfs(no + 1); // 색칠 후 다음 경우의 수로
        if (isCan) return; // 색칠이 가능하면 즉시 빠져나온다. 가장 작은 색을 쓴 경우가 최신이 된다.
        chk[no + 1] = 0; // 색칠이 불가능 했을 경우 해당색을 제외하고 경우의 수를 탐색한다.
    }
}

int main() {
    isCan = false;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> map[i][j];
            map[j][i] = map[i][j];
        }
    }

    dfs(0);

    if (isCan) {
        for (int i = 1; i <= n; i++) {
            cout << chk[i] << " ";
        }
    }
    else {
        cout << "-1";
    }

    return 0;
}

#endif
