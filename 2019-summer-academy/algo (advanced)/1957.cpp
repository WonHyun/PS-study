#include "test-algo.h"
#if (PNUM == 1957)

// 주사위 던지기 2 문제

using namespace std;

int n, m;

int a[8]; // 주사위를 던지는 횟수는 최대 7번
bool check[7]; // 순열용 중복 베제

void dice(int count, int sum) {
    if (count > n) {
        if (sum == m) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        
        return;
    }
    for (int i = 1; i <= 6; i++) {
        // count => 현재 주사위의 위치
        a[count] = i; // count 1, 2, 3 ... n 번 던지기
        dice(count+1, sum + i);
    }
}

void diceP(int count, int sum) {
    if (count > n) {
        if (sum == m) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }

        return;
    }
    for (int i = 1; i <= 6; i++) {
        if (check[i]) continue; // 중복을 막는다
        a[count] = i;
        check[i] = true;
        diceP(count + 1, sum + i);
        check[i] = false;
    }
}

int main() {
    cin >> n >> m;

    dice(1, 0);
    cout << endl;
    diceP(1, 0);

    return 0;
}

#endif
