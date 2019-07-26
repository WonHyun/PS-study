#include "../test-algo.h"
#if (PNUM == 2402)

// 기상 캐스터

using namespace std;

char map[101][102];

int main() {
    bool willCloudy = false;
    int h, w, count = 0;

    cin >> h >> w;

    for (int y = 0; y < h; y++) {
        willCloudy = false;
        for (int x = 0; x < w; x++) {
            cin >> map[y][x];
            if (map[y][x] == 'c') {
                willCloudy = true;
                count = 0;
            }
            if (willCloudy) {
                cout << count << " ";
                count++;
            }
            else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

#endif
