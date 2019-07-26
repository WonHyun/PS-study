#include "test-algo.h"
#if (PNUM == 1735)

// 배열 회전 시키기 90, 180, 270, 360

using namespace std;

int arr[51][51];
int temp[51][51];

void rotate(int n, int angle) {
    int count = angle / 90;
    if (angle != 360) {
        for (int i = 0; i < count; i++) {
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    temp[x][n - y - 1] = arr[y][x];
                }
            }
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    arr[y][x] = temp[y][x];
                }
            }
        }
    }
}

void printArr(int n) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << arr[y][x] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, angle = -1;

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }

    while (angle != 0) {
        cin >> angle;
        if (angle % 90 != 0 || angle == 0) continue;
        rotate(n, angle);
        printArr(n);
    }

    return 0;
}

#endif
