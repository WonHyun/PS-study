#include "test-algo.h"
#if (PNUM == 1704)

// 배수의 합

using namespace std;

int main() {
    int i, n, sum = 0;

    cin >> n;

    for (i = n; sum < 10000; i += n) {
        sum += i;
    }

    cout << i - (n * 2);

    return 0;
}

#endif
