#include "test-algo.h"
#if (PNUM == 1874)

// 색종이 둘레 구하기

using namespace std;

bool squre[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0, };

int main() {
    int n, cx, cy, answer = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cx >> cy;
        for (int y = cy; y < cy + 10 && y < 101; y++) {
            for (int x = cx; x < cx + 10 && x < 101; x++) {
                squre[y][x] = true;
            }
        }
    }

    for (int y = 0; y < 101; y++) {
        for (int x = 0; x < 101; x++) {
            if (squre[y][x]) {
                for (int i = 0; i < 4; i++) {
                    cx = x + dx[i];
                    cy = y + dy[i];
                    if (cx < 0 || cx > 100 || cy < 0 || cy > 100) continue;
                    if (!squre[cy][cx]) answer++;
                }
            }
        }
    }

    cout << answer;

    return 0;
}

#endif
