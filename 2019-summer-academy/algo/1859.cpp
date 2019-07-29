#include "test-algo.h"
#if (PNUM == 1859)

//미로찾기 로봇 방향이 정해진 버전 문제

using namespace std;

char map[12][13];
bool isVisited[12][12];

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

vector<int> dir;

struct robot {
    int x = 1, y = 1, move = 0;
};

int search(robot cur, int nd) {
    while (true) {
        isVisited[cur.y][cur.x] = true;
        robot next;
        next.x = cur.x + dx[dir[nd]];
        next.y = cur.y + dy[dir[nd]];
        next.move = cur.move + 1;
        if (isVisited[next.y][next.x]) {
            return cur.move;
        }
        if (map[next.y][next.x] == '1') {
            next = cur;
            nd++;
            nd %= 4; // 방향전환
        }
        return search(next, nd);
    }
}

int main() {
    int n, d;

    cin >> n;

    for (int y = 0; y <= n + 1; y++) {
        for (int x = 0; x <= n + 1; x++) {
            map[y][x] = '1';
        }
    }

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> map[y][x];
        }
    }

    for (int i = 0; i < 4; i++) {
        cin >> d;
        dir.push_back(d - 1);
    }

    robot cur;

    cout << search(cur, 0);

    return 0;
}

#endif
