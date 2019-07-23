#include "test-algo.h"
#if (PNUM == 2297)

// 토마토 (고) 문제

using namespace std;

struct tomato
{
    int x, y, day = 0;
};

int map[1001][1001];
bool isVisited[1001][1001];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    int c, r, day = -1;
    queue<tomato> q;

    cin >> c >> r;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> map[y][x];
            if (map[y][x] == 1) {
                tomato cur;
                cur.x = x; cur.y = y;
                isVisited[y][x] = true;
                q.push(cur);
            }
        }
    }

    while (!q.empty()) {
        tomato cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            tomato next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.day = cur.day + 1;
            if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r) continue;
            if (isVisited[next.y][next.x] || map[next.y][next.x] == -1) continue;
            day = next.day;
            isVisited[next.y][next.x] = true;
            q.push(next);
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (!isVisited[y][x] && map[y][x] == 0) {
                day = -1;
                break;
            }
        }
    }

    cout << day;

    return 0;
}

#endif
