#include "test-boj.h"
#if (PNUM == 13458)

// 시험감독 문제

#include <iostream>

using namespace std;

int exam[1000001];

int main() {
    int n, b, c;
    long long answer = 0; // 자료형 초과는 언제나 주의!

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> exam[i];
    }

    cin >> b >> c;

    for (int i = 0; i < n; i++) {
        answer++;
        exam[i] -= b;

        if (exam[i] > 0) {
            answer += exam[i] / c;
            exam[i] %= c;

            if (exam[i] > 0) answer++;
        }
    }

    cout << answer;

    return 0;
}
#endif
