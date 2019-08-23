#include "test-boj.h"
#if (PNUM == 14499)

// 주사위 굴리기 문제

// 동 서 북 남


#include <iostream>

using namespace std;

struct dice {
    int x, y;
    int status[4][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
};

int map[21][21];
int n, m, k;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

dice cur;

int dir[1001];

/*
  2
4 1 3
  5
  6

  동

    2
  6 4 1
    5
    3

  서

    2
  1 3 6
    5
    4

  북

    6
  4 2 3
    1
    5

  남

    1
  4 5 3
    6
    2

*/

void changeStatus(int dir) {
    int temp;
    switch (dir)
    {
    case 0:
        temp = cur.status[1][2];
        cur.status[1][2] = cur.status[1][1];
        cur.status[1][1] = cur.status[1][0];
        cur.status[1][0] = cur.status[3][1];
        cur.status[3][1] = temp;
        break;
    case 1:
        temp = cur.status[1][0];
        cur.status[1][0] = cur.status[1][1];
        cur.status[1][1] = cur.status[1][2];
        cur.status[1][2] = cur.status[3][1];
        cur.status[3][1] = temp;
        break;
    case 2:
        temp = cur.status[3][1];
        cur.status[3][1] = cur.status[2][1];
        cur.status[2][1] = cur.status[1][1];
        cur.status[1][1] = cur.status[0][1];
        cur.status[0][1] = temp;
        break;
    case 3:
        temp = cur.status[0][1];
        cur.status[0][1] = cur.status[1][1];
        cur.status[1][1] = cur.status[2][1];
        cur.status[2][1] = cur.status[3][1];
        cur.status[3][1] = temp;
        break;
    }
}

void move(int dir) {
    int nx = cur.x + dx[dir];
    int ny = cur.y + dy[dir];

    if (nx < 0 || nx >= m || ny < 0 || ny >= n) return;
    cur.x = nx; cur.y = ny;
    changeStatus(dir);

    if (map[ny][nx]) {
        cur.status[3][1] = map[ny][nx];
        map[ny][nx] = 0;
    }
    else map[ny][nx] = cur.status[3][1];

    cout << cur.status[1][1] << endl;
}

int main() {
    cin >> n >> m >> cur.y >> cur.x >> k; // x, y를 준다지만, 사실상 y, x를 줌

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> dir[i];
    }

    for (int i = 0; i < k; i++) {
        move(dir[i] - 1);
    }
    
    return 0;
}
#endif
