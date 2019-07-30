#include "test-algo.h"
#if (PNUM == 1975)

// 회전초밥 (고) 문제

using namespace std;

int table[3003001];
int isAte[3001];

int main() {
    int n, d, k, c, max = 0, type = 0;

    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }

    for (int i = 0; i < k; i++) {
        table[n + i] = table[i];
    }

    for (int i = 0; i < k; i++) {
        if (isAte[table[i]]++ == 0) type++;
    }

    max = type;

    for (int i = 0; i < n; i++) {
        if (--isAte[table[i]] == 0) type--; // 첫 번째 초밥 먼저 뺀후 잔량 없으면 개수 차감
        if (isAte[table[i + k]]++ == 0) type++; // k번째 초밥을 신규로 먹을 때 개수 증가
        if (isAte[c] == 0) { // 쿠폰을 신규로 먹을 수 있는 경우
            if (type + 1 > max) max = type + 1; // 쿠폰을 더한 값을 비교
        }
        else {
            if (type > max) max = type; // 쿠폰을 못먹으면 현재 개수 비교
        }
    }

    cout << max;

    return 0;
}

#endif
