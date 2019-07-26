#include "../test-algo.h"
#if (PNUM == 1734)

// 마방진

using namespace std;

int map[101][101];

int main() {
    int n, x, y = 0;
    cin >> n;

    x = n / 2;

    for (int i = 1; i <= n*n; i++) {
        map[y][x] = i;
        if (i % n == 0) {
            y = y + 1 >= n ? 0 : y + 1;
        }
        else {
            x = x - 1 < 0 ? n - 1 : x - 1;
            y = y - 1 < 0 ? n - 1 : y - 1;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << map[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}

#endif
