#include "../test-prog.h"
#if (PNUM == lv02-28)

// 피보나치 수 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibo[100001];


// 문제가 잘못되었음, 최종 답에서 % 1234567을 하는게 아니라
// 각 피보나치 수에 % 1234567을 하면서 구해야 함!

int solution(int n) {
    int answer = 0;

    fibo[1] = 1;

    for (int i = 2; i <= n; i++) {
        fibo[i] = (fibo[i - 2] + fibo[i - 1]) % 1234567;
    }

    return fibo[n];
}

int main() {
    int n = 5;

    cout << solution(n);

    return 0;
}

#endif
