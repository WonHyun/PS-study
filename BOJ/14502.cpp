#include "test-boj.h"
#if (PNUM == 14502)

// 연구소 문제

#include <iostream>
#include <queue>

using namespace std;

struct pos
{
    int x, y;
};

int n, m, maxSafeArea;
int map[9][9];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int max(int a, int b) {
    return a > b ? a : b;
}

int calSafeArea(int curMap[][9]) {
    int wide = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (!curMap[y][x]) wide++;
        }
    }
    return wide;
}

void infect(int curMap[][9]) {
    bool isVisited[9][9];
    queue<pos> q;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            isVisited[y][x] = false;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (curMap[y][x] == 2 && !isVisited[y][x]) {
                pos temp;
                temp.x = x; temp.y = y;
                isVisited[y][x] = true;
                q.push(temp);
                while (!q.empty()) {
                    pos cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        pos next;
                        next.x = cur.x + dx[dir];
                        next.y = cur.y + dy[dir];
                        if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) continue;
                        if (isVisited[next.y][next.x] || curMap[next.y][next.x] == 1) continue;
                        isVisited[next.y][next.x] = true;
                        curMap[next.y][next.x] = 2;
                        q.push(next);
                    }
                }
            }
        }
    }
}

void buildWall(int count, int curMap[][9]) {
    if (count >= 3) {
        int tempMap[9][9];
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                tempMap[y][x] = curMap[y][x];
            }
        }
        infect(tempMap);
        maxSafeArea = max(calSafeArea(tempMap), maxSafeArea);
        return;
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (!curMap[y][x]) {
                curMap[y][x] = 1;
                buildWall(count + 1, curMap);
                curMap[y][x] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }

    buildWall(0, map);

    cout << maxSafeArea;

    return 0;
}
#endif
