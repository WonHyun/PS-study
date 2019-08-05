#if 0

#include <iostream>

// 숫자 찾기 (이진탐색) 문제

using namespace std;

int n, m;

int sorted[50001];

int binarySearch(int s, int e, int target) {
    int ret = 0;
    int mid;

    while (s <= e) {
        mid = (s + e) / 2;
        if (target == sorted[mid]) {
            return mid + 1; // 문제는 1부터 시작
        }
        if (target < sorted[mid]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return ret;
}

int main() {
    int target;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sorted[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> target;
        cout << binarySearch(0, n - 1, target) << endl;
    }

    return 0;
}

#endif
