#include "test-boj.h"
#if (PNUM == 16234)

// 인구이동 문제

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

struct pos {
    int x, y;
};

struct regionInfo {
    int count, sum;
};

int map[51][51];
int region[51][51];
int n, l, r, cnt;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

regionInfo info[2501];
regionInfo emptyInfo;

bool divide() {
    bool isVisited[51][51], isDivided = false;
    int regionNumber = 0;
    queue<pos> q;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            isVisited[y][x] = false;
            region[y][x] = 0;
        }
    }

    for (int i = 0; i <= n * n; i++) {
        info[i] = emptyInfo;
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!isVisited[y][x]) {
                pos temp;
                temp.x = x; temp.y = y;

                regionNumber++;
                isVisited[y][x] = true;
                region[y][x] = regionNumber;
                info[regionNumber].count++; info[regionNumber].sum += map[y][x];

                q.push(temp);

                while (!q.empty()) {
                    pos cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int diff;
                        pos next;
                        next.x = cur.x + dx[dir];
                        next.y = cur.y + dy[dir];
                        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n || isVisited[next.y][next.x]) continue;
                        diff = abs(map[cur.y][cur.x] - map[next.y][next.x]);
                        if (diff < l || diff > r) continue;
                        isDivided = true;
                        isVisited[next.y][next.x] = true;
                        region[next.y][next.x] = regionNumber;
                        info[regionNumber].count++; info[regionNumber].sum += map[next.y][next.x];
                        q.push(next);
                    }
                }
            }
        }
    }
    return isDivided;
}

void move() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            map[y][x] = info[region[y][x]].sum / info[region[y][x]].count;
        }
    }
}

int main() {

    cin >> n >> l >> r;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    while (divide()) {
        move();
        cnt++;
    }

    cout << cnt;

    return 0;
}
#endif
