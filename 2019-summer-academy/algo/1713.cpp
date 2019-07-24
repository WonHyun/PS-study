#include "test-algo.h"
#if (PNUM == 1713)

// 7의 배수 + 짝수 인수

using namespace std;

int main() {

    int i = 0, n;

    cin >> n;

    while (i < n) {
        i += 14;
    }

    if (n <= 14) {
        cout << i;
    }
    else {
        i = (n - (i - 14)) <= (i - n) ? i - 14 : i;
        cout << i;
    }

    return 0;
}

#endif
