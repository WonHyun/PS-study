#include "../test-prog.h"
#if (PNUM == lv03-7)

// 타일 장식물 문제

#include <iostream>

using namespace std;

// 한 변의 길이는 피보나치 수열과 동일
long long dp[81];

// N에 해당하는 사각형의 변의 길이 중, 작은 쪽은 dp[N]이고
// 긴 쪽은 dp[N] + dp[N - 1]이다.

long long solution(int N) {
    dp[1] = 1;

    if (N == 1) return 4;

    // 한 변의 길이 계산
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    // 둘레 계산 후 return
    return dp[N] * 2 + (dp[N - 1] + dp[N]) * 2;
}

int main() {
    int n = 5;

    cout << solution(n);

    return 0;
}
#endif
