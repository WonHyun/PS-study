#include "test-boj.h"
#if (PNUM == 17143)

// 낚시왕 문제

#include <iostream>
#include <queue>

using namespace std;

struct shark
{
    int x, y, size, dir, speed;
};

int r, c, m, fishMan, catched;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int turn[4] = { 1, 0, 3, 2 };

shark blank;
shark map[101][101];
shark temp[101][101];

void init() {
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            map[y][x] = temp[y][x];
            temp[y][x] = blank;
        }
    }
}

int main() {
    queue<shark> q;
    cin >> r >> c >> m;

    for (int i = 0; i < m; i++) {
        shark temp;
        cin >> temp.y >> temp.x >> temp.speed >> temp.dir >> temp.size;
        temp.x--; temp.y--;
        temp.dir--;
        map[temp.y][temp.x] = temp;
    }

    while (fishMan < c) {
        // 상어 잡기
        for (int i = 0; i < r; i++) {
            if (map[i][fishMan].size != 0) {
                catched += map[i][fishMan].size;
                map[i][fishMan] = blank;
                break;
            }
        }

        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                if (map[y][x].size != 0) {
                    q.push(map[y][x]);
                }
            }
        }

        while (!q.empty()) {
            int mx, my;
            shark cur = q.front(); q.pop();
            shark next = cur;
            
            if (cur.dir < 2) {
                //상하 이동
                my = cur.speed % (2 * (r - 1)); // y로 움직여야 하는 수, 2 * (r - 1) 마다 같은 위치, 방향으로 돌아온다.

                for (int i = 0; i < my; i++) {
                    if (next.y + dy[next.dir] < 0 || next.y + dy[next.dir] >= r) { // 범위를 벗어나면
                        next.dir = turn[next.dir]; // 방향전환
                    }
                    next.y += dy[next.dir];
                }
            }
            else {
                //좌우 이동
                mx = cur.speed % (2 * (c - 1)); // x로 움직여야 하는 수, 2 * (c - 1) 마다 같은 위치, 방향으로 돌아온다.

                for (int i = 0; i < mx; i++) {
                    if (next.x + dx[next.dir] < 0 || next.x + dx[next.dir] >= c) {
                        next.dir = turn[next.dir];
                    }
                    next.x += dx[next.dir];
                }
            }

            if (temp[next.y][next.x].size < next.size) { // 가려는 곳의 상어 사이즈 보다 크면
                temp[next.y][next.x] = next; // 그 상어 대신에 들어감
            }
        }

        init(); // map에 해당 상어의 상태를 입력 후 temp배열 초기화

        fishMan++; // 낚시꾼 이동
    }

    cout << catched;

    return 0;
}
#endif
