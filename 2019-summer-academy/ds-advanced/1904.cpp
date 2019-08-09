#if 0

// 예산 문제

#include <iostream>

using namespace std;

int n, m;
int buget[10001];

int chk[10001];

int check(int mid) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (buget[i] > mid) sum += mid; // 요청 예산이 현재 상한가를 초과하면 상한가를 더함
        else sum += buget[i]; // 요청 예산이 상한가 이내에 있으면 요청 예산을 더함
    }

    return sum;
}

int main() {
    int s = 0, e = 0, mid, sol = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> buget[i];
        if (e < buget[i]) e = buget[i];
    }

    cin >> m;

    while (s <= e) {
        mid = (s + e) / 2; // 상한가와 하한가의 중간으로 다음 상한가를 정함
        if (check(mid) <= m) { // 현재 상한가가 예산 범위 안에 있는지 체크
            // 만족하면 상한가를 늘려봄
            s = mid + 1;
            sol = mid;
        }
        else {
            // 만족하지 못하면 상한가를 줄여봄
            e = mid - 1;
        }
    }

    cout << sol;

    return 0;
}



#endif
