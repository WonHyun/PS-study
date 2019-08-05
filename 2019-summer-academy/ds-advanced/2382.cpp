#if 0

// 도약 문제

#include <iostream>
#include <algorithm>

using namespace std;

int leaf[1001];

int binaryLower(int s, int e, int target) {
    int mid, lower = -1;

    while (s <= e) {
        mid = (s + e) / 2;
        if (leaf[mid] >= target) {
            lower = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return lower;
}

int binaryUpper(int s, int e, int target) {
    int mid, upper = -1;

    while (s <= e) {
        mid = (s + e) / 2;
        if (leaf[mid] <= target) {
            upper = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    return upper;
}

int main() {
    int n, l, u, answer = 0, dist;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> leaf[i];
    }

    sort(leaf, leaf + n);

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            dist = leaf[j] - leaf[i];

            l = binaryLower(0, n - 1, leaf[j] + dist);
            if (l == -1 || leaf[l] - leaf[j] > dist * 2) continue;
            u = binaryUpper(0, n - 1, leaf[j] + dist * 2);
            answer += u - l + 1;

            // 삼중 for문으로 풀이
            //for (int k = j + 1; k < n; k++) {
            //    if (leaf[k] - leaf[j] < dist) continue;
            //    if (leaf[k] - leaf[j] > dist * 2) break;
            //    answer++;
            //}
        }
    }

    cout << answer;

    return 0;
}

#endif
