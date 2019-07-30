#include "test-algo.h"
#if (PNUM == 1761)

// 1~n까지의 합 재귀버전 문제 

using namespace std;

// 꼬리 재귀 버전
//int sum(int n, int cal) {
//    if (n == 1) return cal + 1;
//    return sum(n-1, cal + n);
//}

int sum(int n) {
    if (n == 1) return 1;
    return n + sum(n - 1);
}


int main() {
    int n;
    cin >> n;

    cout << sum(n);

    return 0;
}

#endif
