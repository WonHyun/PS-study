#if 0

// 구슬 탈출 게임 문제, 한칸 씩 움직이는 버전

#include <iostream>

using namespace std;

struct ball
{
    int x, y;
};

int n, m, shortest;
char map[16][17];
ball red, blue;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int no, ball red, ball blue) {
    ball cr = red, cb = blue, next;
    bool isEnd, isFault;
    if (no > 10) return;
    for (int i = 0; i < 4; i++) {
        red = cr;
        blue = cb;
        isEnd = false;
        isFault = false;

        next = red;
        next.x += dx[i]; next.y += dy[i];
        if (map[next.y][next.x] == '#') next = red;
        if (map[next.y][next.x] == 'H') isEnd = true;
        red = next;

        next = blue;
        next.x += dx[i]; next.y += dy[i];
        if (map[next.y][next.x] == '#') next = blue;
        if (map[next.y][next.x] == 'H') isFault = true;
        blue = next;

        if (red.x == blue.x && red.y == blue.y) {
            continue;
        }
        if (isFault) continue;
        if (isEnd) {
            if (no < shortest) shortest = no;
            return;
        }
        dfs(no + 1, red, blue);
    }
}

int main() {
    int t, n, m;
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

        dfs(1, red, blue);

        if (shortest == 0x7FFFFFFF) {
            cout << "-1" << endl;
        }
        else {
            cout << shortest << endl;
        }
    }

    return 0;
}

#endif
