#include "test-algo.h"
#if (PNUM == 1810)

// 미로 탈출 로봇

using namespace std;

struct robot
{
    int x, y, time = 0;
};

char map[101][101];
bool isVisited[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    int c, r;
    bool isFind = false;

    queue<robot> q;

    robot start;
    robot arrive;
    robot shortest;

    cin >> c >> r;
    cin >> start.x >> start.y >> arrive.x >> arrive.y;

    start.x--; start.y--; arrive.x--; arrive.y--;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> map[y][x];
        }
    }

    q.push(start);
    isVisited[start.y][start.x] = true;

    while (!q.empty() && !isFind) {
        robot cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            robot next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            next.time = cur.time + 1;
            if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r) continue;
            if (isVisited[next.y][next.x] || map[next.y][next.x] == '1') continue;

            if (next.x == arrive.x && next.y == arrive.y) {
                shortest = next;
                isFind = true;
                break;
            }
            isVisited[next.y][next.x] = true;
            q.push(next);
        }
    }

    cout << shortest.time;

    return 0;
}

#endif
