#include "test-algo.h"
#if (PNUM == 1788)

// 미술관람 대회 문제

using namespace std;

int n;
char map[101][102];
bool isVisited[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int region[2];

void group(int x, int y, char color) {
    int nx, ny;
    isVisited[y][x] = true;

    for (int dir = 0; dir < 4; dir++) {
        nx = x + dx[dir];
        ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (isVisited[ny][nx] || map[ny][nx] != color) continue;
        group(nx, ny, color);
    }
}

void init() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            isVisited[y][x] = false;
        }
    }
}

void greenToRed() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] == 'G') map[y][x] = 'R';
        }
    }
}

int main() {
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    // 일반 참가자를 위한 영역
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!isVisited[y][x]) {
                group(x, y, map[y][x]);
                region[0]++;
            }
        }
    }

    init();
    greenToRed();

    // 적녹 색맹을 위한 영역
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!isVisited[y][x]) {
                group(x, y, map[y][x]);
                region[1]++;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        cout << region[i] << " ";
    }

    return 0;
}

#endif
