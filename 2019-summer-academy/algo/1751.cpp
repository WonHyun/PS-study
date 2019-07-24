#include "test-algo.h"
#if (PNUM == 1751)

// 잃어버린 페이지 문제

using namespace std;

// 경우의 수를 모두 따지기
void answer1(int n, int p) {
    int answer[4];

    if (p <= n / 2) {
        if (p % 2) {
            answer[0] = p + 1;
            answer[1] = n - p;
            answer[2] = n - p + 1;
        }
        else {
            answer[0] = p - 1;
            answer[1] = n - p + 1;
            answer[2] = n - p + 2;
        }
    }
    else {
        if (p % 2) {
            answer[0] = n - p;
            answer[1] = n - p + 1;
            answer[2] = p + 1;
        }
        else {
            answer[0] = n - p + 1;
            answer[1] = n - p + 2;
            answer[2] = p - 1;
        }
    }

    for (int k = 0; k < 3; k++) {
        cout << answer[k] << " ";
    }
}

//반목문 사용하기
void answer2(int n, int p) {
    int answer[4];
    int i;

    bool isFind = false;

    for (i = 1; i < n / 2; i += 2) {
        for (int j = 0; j < 2; j++) {
            if ((i + j) == p) {
                isFind = true;
                break;
            }
        }
        for (int j = 0; j < 2; j++) {
            if ((n - i + j) == p) {
                isFind = true;
                break;
            }
        }
        if (isFind) break;
    }

    answer[0] = i;
    answer[1] = i + 1;
    answer[2] = n - i;
    answer[3] = n - i + 1;

    for (int k = 0; k < 4; k++) {
        if (answer[k] != p) {
            cout << answer[k] << " ";
        }
    }
}

int main() {
    int n, p;

    cin >> n >> p;

    answer1(n, p);
    answer2(n, p);

    return 0;
}

#endif
