#include "test-algo.h"
#if (PNUM == 1726)

// 연속 부분 최대곱

using namespace std;

double arr[10001];

int main() {
    int n;
    double cur, max = 0.0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cur = arr[i];
        if (max < cur) { max = cur; } // 현재 원소의 값이 최대값이면 대입
        for (int j = i + 1; j < n; j++) {
            if (cur * arr[j] < 1) { // 다음걸 곱했을때 0.~~~ 이 되는경우, 더이상 증가할 수 없다
                break;
            }
            cur *= arr[j];
            if (max < cur) { max = cur; }
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << max;

    return 0;
}

#endif
