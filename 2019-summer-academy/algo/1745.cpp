#include "test-algo.h"
#if (PNUM == 1745)

// 주차 요금 문제

using namespace std;

int main() {

    int n, min, charge = 0, cur = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> min;
        if (min >= 10 && min <= 30) {
            charge += 500;
        }

        if (min > 30) {
            min -= 30;
            cur = 500;
            while (min > 0 && cur <= 50000) {
                cur += 300;
                min -= 10;
            }
            if (cur > 50000) charge += 50000;
            else charge += cur;
        }
    }

    cout << charge;

    return 0;
}

#endif
