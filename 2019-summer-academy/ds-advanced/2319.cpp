#if 0

#include <iostream>
#include <cstdio>

// 숫자 카운팅, lower, upper bound 문제
// 실제 제출할 때 c 스타일로 입출력받음, 시간초과 때문에
// cin, cout 가속해서 테스트 해보니 통과됨

using namespace std;

int n, m;

int sorted[200001];

int binarySearchLower(int s, int e, int target) {
    int mid, lower = -1;

    while (s <= e) {
        mid = (s + e) / 2;
        if (sorted[mid] < target) s = mid + 1;
        else {
            if (sorted[mid] == target) lower = mid;
            e = mid - 1;
        }
    }

    return lower;
}

int binarySearchUpper(int s, int e, int target) {
    int mid, upper = -1;

    while (s <= e) {
        mid = (s + e) / 2;
        if (sorted[mid] > target) e = mid - 1;
        else {
            if (sorted[mid] == target) upper = mid;
            s = mid + 1;
        }
    }

    return upper;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target, l, u;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sorted[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> target;
        l = binarySearchLower(0, n - 1, target);
        if (l < 0) cout << 0 << " ";
        else {
            u = binarySearchUpper(l, n - 1, target);
            cout << u - l + 1 << " ";
        }
    }

    return 0;
}

#endif

#if 0

#include <iostream>

// lower, upper bound 문제, 숫자 범위 버전

// 1 1 1 6 9 11 13 17 19 20
// 5~15 사이의 개수 구하기

using namespace std;

int n, m;

int sorted[] = { 1, 1, 1, 6, 9, 11, 13, 17, 19, 20 };

int binarySearchLower(int s, int e, int target) {
    int mid, lower = -1;

    while (s <= e) {
        mid = (s + e) / 2;
        if (sorted[mid] < target) {
            s = mid + 1;
            lower = s;
        }
        else {
            e = mid - 1;
        }
    }

    return lower;
}

int binarySearchUpper(int s, int e, int target) {
    int mid, upper = -1;

    while (s <= e) {
        mid = (s + e) / 2;
        if (sorted[mid] > target) {
            e = mid - 1;
            upper = e;
        }
        else {
            s = mid + 1;
        }
    }

    return upper;
}

int main() {

    int target, l, u;

    l = binarySearchLower(0, 9, 5);
    if (l < 0) cout << 0 << " ";
    else {
        u = binarySearchUpper(l, 9, 15);
        cout << u - l + 1 << " ";
    }

    return 0;
}

#endif
