#include "../test-algo.h"
#if (PNUM == 1210)

// 토마토 (초), 3차원 문제 

using namespace std;

int m, n, h;
int sol;

struct tomato
{
    int x, y, z, day = 0;
};

int map[101][101][101];
bool isVisited[101][101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int dz[2] = { 1, -1 };

int main(void)
{
    bool isComplited = true;
    int day = -1;
    queue<tomato> q;
    cin >> m >> n >> h;

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> map[z][y][x];
                if (map[z][y][x] == 1) {
                    tomato cur;
                    cur.x = x; cur.y = y; cur.z = z;
                    isVisited[z][y][x] = true;
                    q.push(cur);
                }
                if (map[z][y][x] == 0) isComplited = false;
            }
        }
    }

    while (!q.empty()) {
        tomato cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            tomato next = cur;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.day = cur.day + 1;
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
            if (isVisited[next.z][next.y][next.x] || map[next.z][next.y][next.x] == -1) continue;
            day = next.day;
            isVisited[next.z][next.y][next.x] = true;
            q.push(next);
        }
        for (int i = 0; i < 2; i++) {
            tomato next = cur;
            next.z = cur.z + dz[i];
            next.day = cur.day + 1;
            if (next.z < 0 || next.z >= h) continue;
            if (isVisited[next.z][next.y][next.x] || map[next.z][next.y][next.x] == -1) continue;
            day = next.day;
            isVisited[next.z][next.y][next.x] = true;
            q.push(next);
        }
    }

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (!isVisited[z][y][x] && map[z][y][x] == 0) {
                    day = -1;
                    break;
                }
            }
        }
    }

    if (isComplited) day = 0;

    cout << day;

    return 0;
}

#endif
