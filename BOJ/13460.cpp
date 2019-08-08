#include "test-boj.h"
#if (PNUM == 13460)

// 구슬탈출 문제
#include <iostream>

using namespace std;

struct ball
{
    int x, y;
};

int n, m, shortest;
char map[11][12];
ball red, blue;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int no, ball red, ball blue) {
    int rm, bm;
    ball cr = red, cb = blue;
    bool isEnd, isFault;
    if (no > 10) return;
    for (int i = 0; i < 4; i++) {
        red = cr;
        blue = cb;
        isEnd = false;
        isFault = false;
        rm = 0;
        bm = 0;
        while (true) {
            ball next = red;
            next.x += dx[i]; next.y += dy[i];
            if (map[next.y][next.x] == '#') break;
            if (map[next.y][next.x] == 'O') {
                isEnd = true;
                break;
            }
            red = next;
            rm++;
        }
        while (true) {
            ball next = blue;
            next.x += dx[i]; next.y += dy[i];
            if (map[next.y][next.x] == '#') break;
            if (map[next.y][next.x] == 'O') {
                isFault = true;
                break;
            }
            blue = next;
            bm++;
        }
        if (red.x == blue.x && red.y == blue.y) {
            if (rm > bm) {
                red.x -= dx[i];
                red.y -= dy[i];
            }
            else {
                blue.x -= dx[i];
                blue.y -= dy[i];
            }
        }
        if (isFault) continue;
        if (isEnd) {
            if (no < shortest) shortest = no;
            return;
        }
        if (cr.x == red.x && cr.y == red.y && cb.x == blue.x && cb.y == blue.y) continue; // 골인 한 경우 주의!
        dfs(no + 1, red, blue);
    }
}

int main() {
    shortest = 0x7FFFFFFF;
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
            if (map[y][x] == 'R') {
                red.x = x;
                red.y = y;
            }
            if (map[y][x] == 'B') {
                blue.x = x;
                blue.y = y;
            }
        }
    }

    dfs(1, red, blue);

    if (shortest == 0x7FFFFFFF) {
        cout << "-1";
    }
    else {
        cout << shortest;
    }
    
    return 0;
}
#endif

#if 0

// 구슬탈출, 테스트 케이스 테스트용
// https://boohyunsik.github.io/exit-marble-test-case/

#include <iostream>

using namespace std;

struct ball
{
    int x, y;
};

int n, m, shortest, answer, t;
char map[11][12];
ball red, blue;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int no, ball red, ball blue) {
    int rm, bm;
    ball cr = red, cb = blue;
    bool isEnd, isFault;
    if (no > 10) return;
    for (int i = 0; i < 4; i++) {
        red = cr;
        blue = cb;
        isEnd = false;
        isFault = false;
        rm = 0;
        bm = 0;
        while (true) {
            ball next = red;
            next.x += dx[i]; next.y += dy[i];
            if (map[next.y][next.x] == '#') break;
            if (map[next.y][next.x] == 'O') {
                isEnd = true;
                break;
            }
            red = next;
            rm++;
        }
        while (true) {
            ball next = blue;
            next.x += dx[i]; next.y += dy[i];
            if (map[next.y][next.x] == '#') break;
            if (map[next.y][next.x] == 'O') {
                isFault = true;
                break;
            }
            blue = next;
            bm++;
        }
        if (red.x == blue.x && red.y == blue.y) {
            if (rm > bm) {
                red.x -= dx[i];
                red.y -= dy[i];
            }
            else {
                blue.x -= dx[i];
                blue.y -= dy[i];
            }
        }
        if (isFault) continue;
        if (isEnd) {
            if (no < shortest) shortest = no;
            return;
        }
        if (cr.x == red.x && cr.y == red.y && cb.x == blue.x && cb.y == blue.y) continue;
        dfs(no + 1, red, blue);
    }
}

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        shortest = 0x7FFFFFFF;
        cin >> n >> m;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> map[y][x];
                if (map[y][x] == 'R') {
                    red.x = x;
                    red.y = y;
                }
                if (map[y][x] == 'B') {
                    blue.x = x;
                    blue.y = y;
                }
            }
        }

        cin >> answer;

        dfs(1, red, blue);

        shortest = shortest == 0x7FFFFFFF ? -1 : shortest;
        if (shortest == answer) {
            cout << "correct"<< endl;
        }
        else {
            cout << "wrong!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }
    return 0;
}
#endif
