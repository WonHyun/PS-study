#include "test-algo.h"
#if (PNUM == 1781)

// 악수 문제

using namespace std;

struct stupid
{
    int x, y, count = 0;
};

queue<stupid> q;

char map[52][52];

// 천상계 무빙
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int main() {
    int r, c, cx, cy, answer = 0, count = 0;
    stupid max;

    cin >> r >> c;

    // 민수가 갈곳은 어디?

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            cin >> map[y][x];
            if (map[y][x] == '.') {
                stupid minsu;
                minsu.x = x;
                minsu.y = y;
                q.push(minsu);
            }
        }
    }

    // 어디로 가야하오

    while (!q.empty()) {
        count = 0;
        stupid cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            cx = cur.x + dx[i];
            cy = cur.y + dy[i];
            if (cx < 0 || cx >= c || cy < 0 || cy >= r) continue;
            if (map[cy][cx] != 'o') continue;
            count++;
        }
        cur.count = count;
        if (max.count < cur.count) { max = cur; }
        if (cur.count == 8) { break; }
    }

    // 여기로

    map[max.y][max.x] = 'o';

    // 악수회 시작

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (map[y][x] == 'o') {
                for (int i = 0; i < 8; i++) {
                    cx = x + dx[i];
                    cy = y + dy[i];
                    if (cx < 0 || cx >= c || cy < 0 || cy >= r) continue;
                    if (map[cy][cx] != 'o') continue;
                    answer++;
                }
            }
        }
    }

    cout << answer / 2;

    return 0;
}

#endif
