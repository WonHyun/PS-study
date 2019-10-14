#if 0

// 스티커 문제
// 가장 최대가 되는 값을 찾기

#include <iostream>
#include <vector>

using namespace std;

int dp[100001];

int max(int a, int b) {
    return a > b ? a : b;
}

int calMaxValue(int first, int second, vector<int> sticker) {
    dp[0] = first;
    dp[1] = second;
    for (int i = 2; i < sticker.size(); i++) {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    return dp[sticker.size() - 1];
}

int solution(vector<int> sticker) {
    int maxValue = 0, answer = 0;

    if (sticker.size() == 1) return sticker[0];
    if (sticker.size() == 2) return max(sticker[0], sticker[1]);

    maxValue = calMaxValue(sticker[0], sticker[0], sticker);
    if (maxValue > answer) answer = maxValue;

    maxValue = calMaxValue(0, sticker[1], sticker);
    if (maxValue > answer) answer = maxValue;

    return answer;
}

int main() {
    vector<int> sticker = {30, 40, 90, 100, 70};

    cout << solution(sticker);

    return 0;
}

#endif
