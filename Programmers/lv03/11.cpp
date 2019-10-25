#include "../test-prog.h"
#if (PNUM == lv03-11)

// 등굣길 문제

#include <iostream>
#include <vector>

using namespace std;

long long dp[101][101], map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 0; i < puddles.size(); i++) {
        map[puddles[i][1]][puddles[i][0]] = -1;
    }

    // 1, 1을 집으로 보고 최초 초기화
    dp[0][1] = 1; // dp[1][0] = 1 도 상관없음

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] < 0) continue; // 물 웅덩이인 경우 스킵
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
        }
    }

    return dp[n][m];
}

int main() {
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { {2, 2} };

    cout << solution(m, n, puddles);

    return 0;
}
#endif
