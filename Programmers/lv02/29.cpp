#include "../test-prog.h"
#if (PNUM == lv02-29)

// 다음 큰 숫자 문제

#include <iostream>

using namespace std;

int bitCount(int n) {
    int count = 0, pos = 1;

    for (int i = 0; i < 16; i++) {
        if (n & pos) count++;
        pos = pos << 1;
    }

    return count;
}

int solution(int n) {
    int curCount = bitCount(n), nextCount = 0;

    while (n <= 1000000) {
        n++;
        nextCount = bitCount(n);
        if (curCount == nextCount) break;
    }

    return n;
}

int main() {
    int n = 78;

    cout << solution(n);

    return 0;
}

#endif
