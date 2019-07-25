#include "test-algo.h"
#if (PNUM == 1721)

// 주사위 눈의 합

using namespace std;

int dice[6] = { 1,2,3,4,5,6 };

int main() {
    int n, count = 0;
    cin >> n;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (dice[i] + dice[j] == n) count++; // 경우의 수 더하기
        }
    }

    cout << fixed;
    cout.precision(4);
    cout << ((double)count / 36.0) * 100.0 << "%";

    return 0;
}

#endif
