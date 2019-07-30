#include "test-algo.h"
#if (PNUM == 1805)

// 영역 구하기 문제

using namespace std;

int m, n, k;

int map[101][101];
bool isVisited[101][101];

vector<int> region;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int group(int x, int y, int count) {
    int nx, ny;
    isVisited[y][x] = true;

    for (int dir = 0; dir < 4; dir++) {
        nx = x + dx[dir];
        ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (isVisited[ny][nx] || map[ny][nx] != 0) continue;
        count++;
        count = group(nx, ny, count);
    }
    return count;
}

int main() {
    int cx, cy, nx, ny;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> cx >> cy >> nx >> ny;
        for (int y = cy; y < ny; y++) {
            for (int x = cx; x < nx; x++) {
                map[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] == 0 && !isVisited[y][x]) {
                region.push_back(group(x, y, 1));
            }
        }
    }

    sort(region.begin(), region.end());

    cout << region.size() << endl;

    for (int i = 0; i < region.size(); i++) {
        cout << region[i] << " ";
    }

    return 0;
}

#endif
