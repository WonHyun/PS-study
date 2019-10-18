#include "test-boj.h"
#if (PNUM == 14501)

// 퇴사 문제

#include <iostream>
#include <vector>

using namespace std;

int dp[16]; // n일 째의 최대 이익

struct consult {
    int dur, pay;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    vector<consult> consults;
    consult cons;
    int n, answer = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cons.dur >> cons.pay;
        consults.push_back(cons);
    }

    // i일 까지의 최대 이익을 구한다
    // n일 까지 상담의뢰를 받고, n + 1일 까지 마칠 수 있다 (퇴사일)
    // 즉 n + 1일 까지의 최대 이익을 수령할 수 있다
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j < i; j++) {
            // i일 이전 j일까지의 최대값으로 갱신
            dp[i] = max(dp[i], dp[j]);
            // j일의 상담을 i일 전까지 끝낼 수 있는 경우 최대값으로 갱신
            if (j + consults[j].dur <= i) {
                dp[i] = max(dp[i], dp[j] + consults[j].pay);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}
#endif
