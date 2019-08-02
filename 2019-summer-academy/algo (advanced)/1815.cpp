#include "test-algo.h"
#if (PNUM == 1815)

// 로봇 문제

using namespace std;

struct robot
{
    int x, y, dir, order = 0;
};

int m, n;

int map[101][101];
bool isVisited[4][101][101];

// 동 서 남 북

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

// 오른쪽, 왼쪽 턴
int dt[4][2] = { {3, 2}, {2, 3}, {0, 1}, {1, 0} };

int main(void)
{
    robot start, end, arrive;
    queue<robot> q;
    cin >> m >> n;

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    cin >> start.y >> start.x >> start.dir;
    cin >> end.y >> end.x >> end.dir;

    start.x--; start.y--;
    end.x--; end.y--;

    start.dir--;
    end.dir--;

    q.push(start);
    while (!q.empty()) {
        robot cur = q.front(); q.pop();
        
        if (cur.x == end.x && cur.y == end.y && cur.dir == end.dir) {
            arrive = cur;
            break;
        }

        isVisited[cur.dir][cur.y][cur.x] = true;

        //go k 동작
        robot next = cur;
        next.order = cur.order + 1;
        for (int i = 1; i <= 3; i++) {
            next.x = cur.x + dx[cur.dir] * i; // i를 곱해주면 i칸만큼 전진함
            next.y = cur.y + dy[cur.dir] * i;
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m || isVisited[next.dir][next.y][next.x]) continue;
            if (map[next.y][next.x] == 1) break;
            isVisited[next.dir][next.y][next.x] = true;
            q.push(next);
        }

        for (int i = 0; i < 2; i++) {
            next = cur;
            next.order = cur.order + 1;
            next.dir = dt[cur.dir][i];

            if (isVisited[next.dir][next.y][next.x]) continue;
            isVisited[next.dir][next.y][next.x] = true;
            q.push(next);
        }
    }

    cout << arrive.order;

    return 0;
}

#endif
