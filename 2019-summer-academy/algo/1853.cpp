#include "test-algo.h"
#if (PNUM == 1853)

// 패턴 매칭 문제, 회전포함

using namespace std;

char arr[101][102];
char pat[101][102];
char temp[101][102];


void rotatePatternRight(int p) {
    for (int y = 0; y < p; y++) {
        for (int x = 0; x < p; x++) {
            temp[x][p - y - 1] = pat[y][x];
        }
    }
    for (int y = 0; y < p; y++) {
        for (int x = 0; x < p; x++) {
            pat[y][x] = temp[y][x];
        }
    }
}

int patternMatching(int n, int p) {
    bool isMatch = true;
    int count = 0;

    for (int y = 0; y < n; y++) {
        if (y + p > n) break;

        for (int x = 0; x < n; x++) {
            if (x + p > n) break;
            for (int k = 0; k < 4; k++) {
                isMatch = true;
                for (int i = 0; i < p && isMatch; i++) {
                    for (int j = 0; j < p; j++) {
                        if (arr[y + i][x + j] != pat[i][j]) {
                            isMatch = false;
                            break;
                        }
                    }
                }
                if (isMatch) count++;
                rotatePatternRight(p);
            }
            rotatePatternRight(p);
        }
    }

    return count;
}

int main() {
    int n, p;

    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }

    cin >> p;

    for (int y = 0; y < p; y++) {
        for (int x = 0; x < p; x++) {
            cin >> pat[y][x];
        }
    }

    cout << patternMatching(n, p);

    return 0;
}

#endif
