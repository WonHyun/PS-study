#include "test-algo.h"
#if (PNUM == 1757)

// 숫자근 문제

using namespace std;

int calDigitRoot(int num)
{
    int digitRoot = 0;
    while (num != 0) {
        digitRoot += num % 10;
        num /= 10;
    }
    if (digitRoot > 9) {
        return calDigitRoot(digitRoot);
    }
    else {
        return digitRoot;
    }
}

int main() {
    int n, num, cur, maxRoot = 0, max = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cur = calDigitRoot(num);
        if (maxRoot < cur) {
            maxRoot = cur;
            max = num;
        }
        if (maxRoot == cur) {
            max = max <= num ? max : num;
        }
    }

    cout << max;

    return 0;
}

#endif
