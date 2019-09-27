#if 0

// 코니와 문의 술래잡기 문제

#include <iostream>
#include <vector>

using namespace std;

//현재 지점의 최단거리 경우의 수는 이전 최단거리 경우의 수들의 합이다
unsigned long long dp[25][25];

//틀린 풀이 (계산 미스, 범위 초과)
//unsigned long long calPathCount(int shorest, int row, int col) {
//    unsigned long long ret = 1;
//    unsigned long long div = 1;
//    int max = row > col ? row : col;
//    int rest = row < col ? row : col;
//
//    for (int i = shorest; i > max; i--) {
//        ret *= i;
//    }
//
//    for (int i = rest; i > 0; i--) {
//        div *= i;
//    }
//
//    return ret / div;
//}

int main() {
    int answer = 0;
    int m, n, x, y;

    cin >> m >> n;
    cin >> x >> y;

    if (x >= m || x < 0 || y >= n || y < 0) {
        cout << "fail";
    }
    else {
        for (int cy = 0; cy <= y; cy++) {
            dp[cy][0] = 1;
        }

        for (int cx = 0; cx <= x; cx++) {
            dp[0][cx] = 1;
        }

        for (int cy = 1; cy <= y; cy++) {
            for (int cx = 1; cx <= x; cx++) {
                dp[cy][cx] = dp[cy - 1][cx] + dp[cy][cx - 1];
            }
        }

        cout << x + y << endl;
        cout << dp[y][x];
    }

    return 0;
}

#endif
