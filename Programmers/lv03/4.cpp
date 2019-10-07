#include "../test-prog.h"
#if (PNUM == lv03-4)

// 4단 고음 문제

// 언제나 * 하나에 ++ 가 올 수 있다

#include <iostream>
#include <cmath>

using namespace std;

int answer;

void dfs(int n, int plusCount) {
    if (pow(3, plusCount / 2) > n) return; // plusCount 2개마다 나누기 3을 할 수 있음, 즉 플러스의 개수에 비해 *이 더 추가될 수 없는 경우 탈출
    if (n == 3 && plusCount == 2) answer++; // 나누기 3으로 원래음정인 1로 갈 수 있는 경우
    if (n > 3) {
        if (n % 3 == 0 && plusCount >= 2) dfs(n / 3, plusCount - 2); // 나누기 3을 할 수 있는 경우 (*)
        dfs(n - 1, plusCount + 1); // 빼기 1을 하는 경우 (+)
    }
}

int solution(int n) {
    answer = 0;
    dfs(n, 0);
    return answer;
}

int main() {
    int n = 41;

    cout << solution(n);

    return 0;
}

#endif
