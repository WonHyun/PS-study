#include "../test-prog.h"
#if (PNUM == lv01-6)
//소수 개수 구하기
//반목문의 범위를 조심!
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int answer = 0;
    bool isPrime[1000001];

    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            answer++;
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    cout << answer;

    return 0;
}
/*
초기화하는 로드를 없애기
using namespace std;

bool isNotPrime[1000001];

int solution(int n) {
    int answer = 0;

    for (int i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            answer++;
            for (int j = i * 2; j <= n; j += i) {
                isNotPrime[j] = true;
            }
        }
    }

    return answer;
}
*/
#endif
