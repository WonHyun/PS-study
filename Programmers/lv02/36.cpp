#include "../test-prog.h"
#if (PNUM == lv02-36)

// 점프와 순간이동 문제

#include <iostream>

using namespace std;

int solution(int n)
{
    int answer = 0;

    while (n > 0) {
        if (n % 2 == 0) n /= 2;
        else {
            n -= 1;
            answer++;
        }
    }

    return answer;
}

// 더 간단한 풀이
// 홀수인 경우 answer가 +1 되므로 n의 비트 중 1인 것의 개수를 새도 된다
// ex> 5 => 1001 => 2번, 5000 => 1001110001000 => 5번

/*
python은 2줄로 풀 수 있음

def solution(n):
    return bin(n).count('1')
*/

int solution2(int n)
{
    int answer = 0;

    for (int i = 0; i < 16; i++) {
        if (n & (1 << i)) answer++;
    }

    return answer;
}

int main() {
    int n = 5000;

    cout << solution(n);

    return 0;
}

#endif
