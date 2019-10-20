#include "test-boj.h"
#if (PNUM == 1475)

// 방 번호 문제

// 6과 9의 처리를 신경써야 함

#include <iostream>
#include <string>

using namespace std;

int num[10]; // 0~9, 6은 9로 취급

int main() {
    int cur, max = 0;
    string n;

    cin >> n;

    for (int i = 0; i < n.length(); i++) {
        cur = n[i] - '0';
        if (cur == 6) cur = 9;
        num[cur]++;
    }

    num[9] = num[9] / 2 + num[9] % 2;

    for (int i = 0; i < 10; i++) {
        if (num[i] > max) max = num[i];
    }

    cout << max;

    return 0;
}
#endif
