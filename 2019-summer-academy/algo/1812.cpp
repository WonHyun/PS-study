#include "test-algo.h"
#if (PNUM == 1812)

// 보물섬 문제

using namespace std;

struct land {
    int x, y, count = 0;
};

char map[52][52];
bool isVisited[51][51];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0, };

void init() {
    for (int y = 0; y < 51; y++) {
        for (int x = 0; x < 51; x++) {
            isVisited[y][x] = false;
        }
    }
}

int main() {
    queue<land> q;
    int r, c, max = 0;

    cin >> r >> c;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (map[y][x] == 'L') {
                land cur; cur.x = x; cur.y = y;
                isVisited[y][x] = true;
                q.push(cur);
                while (!q.empty()) {
                    land temp = q.front(); q.pop();
                    for (int i = 0; i < 4; i++) {
                        land next;
                        next.x = temp.x + dx[i];
                        next.y = temp.y + dy[i];
                        next.count = temp.count + 1;
                        if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r) continue;
                        if (isVisited[next.y][next.x] || map[next.y][next.x] != 'L') continue;
                        isVisited[next.y][next.x] = true;
                        q.push(next);
                        if (next.count > max) max = next.count;
                    }
                }
                init();
           }
        }
    }

    cout << max;

    return 0;
}

#endif
