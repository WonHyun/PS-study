#include "../test-prog.h"
#if (PNUM == lv03-2)

// N으로 표현 문제

// DP 문제가 아니라 완전탐색 문제인듯

#include <iostream>

using namespace std;

int mini;

void dfs(int N, int number, int cnt, int sum) {
    if (cnt >= mini) return;
    if (sum == number) {
        if (cnt < mini) mini = cnt;
        return;
    }
    int nCount = 0, n = 0;

    for (int i = 1; i <= 10000000; i *= 10) { // 최대 8자리
        nCount++; // N을 사용한 횟수 증가
        if (nCount + cnt >= mini) continue; // 지금 N을 사용한 횟수 + 여태까지 N을 사용한 횟수 >= minimum 이면 스킵

        n += N * i; // n => N | NN | NNN | NNNN | NNNNN | NNNNNN | NNNNNNN | NNNNNNNN
        
        dfs(N, number, cnt + nCount, sum + n); // 더하는 경우
        dfs(N, number, cnt + nCount, sum - n); // 빼는 경우
        dfs(N, number, cnt + nCount, sum * n); // 곱하는 경우
        dfs(N, number, cnt + nCount, sum / n); // 나누는 경우
    }
}

int solution(int N, int number) {
    mini = 9;
    dfs(N, number, 0, 0);
    if (mini == 9) return -1;
    return mini;
}

int main() {
    int N = 5;
    int number = 12;

    cout << solution(N, number);

    return 0;
}
#endif
