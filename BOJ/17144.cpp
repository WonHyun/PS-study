#include "test-boj.h"
#if (PNUM == 17144)

// 미세먼지 안녕 문제

#include <iostream>
#include <queue>

using namespace std;

struct pos {
    int x, y, mount = 0;
};

pos cleaner;

int r, c, t;

int map[51][51];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// 미세먼지 확산
void spreadDust() {
    queue<pos> q;
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (map[y][x] > 4) { // 확산량이 1 이상인 먼지만 큐에 push
                pos dust;
                dust.x = x; dust.y = y;
                dust.mount = map[y][x];
                q.push(dust);
            }
        }
    }
    while (!q.empty()) {
        pos cur = q.front(); q.pop();
        int mount = cur.mount / 5;
        for (int dir = 0; dir < 4; dir++) {
            pos next;
            next.x = cur.x + dx[dir];
            next.y = cur.y + dy[dir];
            if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r) continue;
            if (map[next.y][next.x] == -1) continue; // 공기 청정기에는 확산하지 않는다
            map[next.y][next.x] += mount;
            map[cur.y][cur.x] -= mount;
        }
    }
}

// 미세먼지 총량 계산
int calDustMount() {
    int sum = 0;
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (map[y][x] > 0) {
                sum += map[y][x];
            }
        }
    }
    return sum;
}

// 공기청정기 가동
void doClean() {
    int cx;
    int cy;

    //아래
    cx = cleaner.x;
    cy = cleaner.y + 1;

    while (cy  + 1 < r) {
        map[cy][cx] = map[cy + 1][cx];
        cy++;
    }

    while (cx + 1 < c) {
        map[cy][cx] = map[cy][cx + 1];
        cx++;
    }

    while (cy - 1 >= cleaner.y) {
        map[cy][cx] = map[cy - 1][cx];
        cy--;
    }

    while (cx - 1 > cleaner.x) {
        map[cy][cx] = map[cy][cx - 1];
        cx--;
    }
    map[cy][cx] = 0;


    //위
    cx = cleaner.x;
    cy = cleaner.y - 2;

    while (cy - 1 >= 0) {
        map[cy][cx] = map[cy - 1][cx];
        cy--;
    }

    while (cx + 1 < c) {
        map[cy][cx] = map[cy][cx + 1];
        cx++;
    }

    while (cy + 1 <= cleaner.y - 1) {
        map[cy][cx] = map[cy + 1][cx];
        cy++;
    }

    while (cx - 1 > cleaner.x) {
        map[cy][cx] = map[cy][cx - 1];
        cx--;
    }
    map[cy][cx] = 0;
}

int main() {
    cin >> r >> c >> t;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> map[y][x];
            if (map[y][x] == -1) {
                cleaner.x = x; cleaner.y = y;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        spreadDust();
        doClean();
    }

    cout << calDustMount();

    return 0;
}
#endif
