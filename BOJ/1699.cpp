#include "test-boj.h"
#if (PNUM == 1699)

//제곱수의 합 문제
#include <iostream>

using namespace std;

int dp[100001];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = i; // 1^2 로만 구성되었을때 항의 개수
    }

    /*
    dp[1] = 1 // 1^2
    dp[2] = 2 // 1^2 + 1^2
    dp[3] = 3 // 1^2 + 1^2 + 1^2
    dp[4] = 4 (1로만 구성) or 1 (2의 제곱수 4) 중 최솟값인 1
    dp[5] = 5 or 2^2 + 2^2 + 1^2 => 3 중 최솟값인 3
    dp[6] = 6 or 2^2 + 2^2 + 2^2 => 3 중 최솟값인 3
    ...
    dp[9] = 9 or 2^2 + 2^2 + 2^2 + 2^2 + 1^2 => 5 or 3^2 => 1 중 최솟값인 1
    ...
    */

    for (int i = 4; i <= n; i++) {
        // 밑의 수 제곱수 탐방
        for (int j = 2; j * j <= i; j++) { // j의 제곱이 i보다 크면 루프종료
            dp[i] = min(dp[i], dp[i - j * j] + 1); // i - j * j => 현재 제곱수를 뺀 나머지 값에 대한 항의 최솟값, + 1 은 j * j를 뺀 항의 값
        }
    }

    cout << dp[n];

    return 0;
}
#endif
