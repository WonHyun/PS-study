#include "../test-prog.h"
#if (PNUM == lv03-12)

// N-Queen 문제

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[13][13], chk[13], answer, boardSize;

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

bool validate() {
    int nx, ny;
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            if (map[y][x]) {
                for (int dir = 0; dir < 8; dir++) {
                    nx = x; ny = y;
                    while (true) {
                        nx += dx[dir];
                        ny += dy[dir];
                        if (nx < 0 || nx >= boardSize || ny < 0 || ny >= boardSize) break;
                        if (map[ny][nx]) return false;
                    }
                }
            }
        }
    }
    return true;
}

void nQueen(int no) {
    if (no >= boardSize) {
        if (validate()) answer++;
        return;
    }
    for (int i = 0; i < boardSize; i++) {
        if (map[no][i] || chk[i]) continue;
        chk[i]++;
        map[no][i]++;
        nQueen(no + 1);
        chk[i]--;
        map[no][i]--;
    }
}

void queen(int y, int x, bool isSet) {
    int cx, cy, bit = -1;
    if (isSet) bit = 1;
    map[y][x] += bit;
    for (int dir = 0; dir < 8; dir++) {
        cx = x;
        cy = y;
        while (true) {
            cx += dx[dir];
            cy += dy[dir];
            if (cx < 0 || cx >= boardSize || cy < 0 || cy >= boardSize) break;
            map[cy][cx] += bit;
        }
    }
}

void dfs(int no)
{
    if (no >= boardSize) {
        answer++;
        return;
    }

    for (int i = 0; i < boardSize; i++) {
        if (map[no][i] || chk[i]) continue;
        chk[i]++;
        queen(no, i, true);
        dfs(no + 1);
        chk[i]--;
        queen(no, i, false);
    }

    return;
}

// 퀸의 모든 방향을 탐색하는 방법 (마지막 TC 시간초과)
int solution1(int n) {
    boardSize = n;
    nQueen(0);
    return answer;
}

// 퀸을 놓으면서 퀸이 놓일 수 없는 공간을 체크하는 경우 (모든 TC 통과)
int solution2(int n) {
    boardSize = n;
    dfs(0);
    return answer;
}

int main() {
    int n = 4;

    cout << solution1(n) << endl;
    cout << solution2(n);

    return 0;
}
#endif
