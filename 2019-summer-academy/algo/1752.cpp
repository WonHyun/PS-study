#include "test-algo.h"
#if (PNUM == 1752)

// 폭탄 돌리기

using namespace std;

int main() {

    int k, n, t;
    int curTime = 0;
    char z;

    cin >> k >> n;

    while (n != 0) {
        cin >> t >> z;
        curTime += t;
        if (curTime > 210) break;
        if (z == 'T') {
            n--;
            k = (k + 1) > 8 ? 1 : k + 1;
        }
    }

    cout << k;

    return 0;
}

#endif
