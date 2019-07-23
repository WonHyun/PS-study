#include "test-algo.h"
#if (PNUM == 1814)

// 저글링 방사능 오염 문제

using namespace std;

struct cloud
{
    int x, y, time = 0;
};

char map[102][102];
bool isVisited[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    queue<cloud> q;
    cloud start;
    int c, r, last = 0, alive = 0;

    cin >> c >> r;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> map[y][x];
        }
    }

    cin >> start.x >> start.y;

    start.x--; start.y--;

    q.push(start);
    isVisited[start.y][start.x] = true;

    while (!q.empty()) {
        cloud cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            cloud next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.time = cur.time + 1;
            if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r) continue;
            if (isVisited[next.y][next.x] || map[next.y][next.x] == '0') continue;

            isVisited[next.y][next.x] = true;
            last = next.time;
            q.push(next);
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (!isVisited[y][x] && map[y][x] == '1') alive++;
        }
    }

    cout << last + 3 << endl;
    cout << alive;

    return 0;
}

#endif
