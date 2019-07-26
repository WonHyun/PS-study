#include "test-algo.h"
#if (PNUM == 1729)

// 가장 큰 행, 열의 위치

#include <limits.h>

using namespace std;

int main() {
    int max = INT_MIN, maxIdx = 0, sum = 0;
    int a[4][5] = { {3, -5, 12, 3, -21}, {-2, 11, 2, -7, -11}, {21, -21, -35, -93, -11}, {9, 14, 39, -98, -1} };

    for (int i = 0; i < 4; i++) {
        sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += a[i][j];
        }
        if (max < sum) {
            max = sum;
            maxIdx = i;
        }
    }

    cout << maxIdx + 1 << " ";

    max = INT_MIN; maxIdx = 0;

    for (int i = 0; i < 5; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += a[j][i];
        }
        if (max < sum) {
            max = sum;
            maxIdx = i;
        }
    }

    cout << maxIdx + 1;

    return 0;
}

#endif
