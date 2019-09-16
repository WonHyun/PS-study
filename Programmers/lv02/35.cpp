#include "../test-prog.h"
#if (PNUM == lv02-35)

// 예상 대진표 문제

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    if (a > b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    while (true) {
        if (a % 2 == 1 && a + 1 == b) return answer;
        a = ceil(a / 2.0);
        b = ceil(b / 2.0);
        answer++;
    }
}

// 더 간단한 풀이
int solution2(int n, int a, int b)
{
    int answer = 0;

    while (a != b) {
        a = a / 2 + a % 2;
        b = b / 2 + b % 2;
        answer++;
    }

    return answer;
}

int main() {
    int n = 8;
    int a = 4;
    int b = 7;

    cout << solution(n, a, b);

    return 0;
}

#endif
