#include "test-algo.h"
#if (PNUM == 1872)

// 색종이 넓이 구하기

using namespace std;

bool squre[101][101];

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
            if (squre[y][x]) answer++;
        }
    }

    cout << answer;

    return 0;
}

#endif
