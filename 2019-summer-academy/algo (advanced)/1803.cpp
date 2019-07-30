#include "test-algo.h"
#if (PNUM == 1803)

// 단지 번호붙이기 문제

// flood fill 이용

using namespace std;

int n;

char map[26][27];
bool isVisited[26][26];

vector<int> region;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int group(int x, int y, int count) {
    int nx, ny;
    isVisited[y][x] = true;

    for (int dir = 0; dir < 4; dir++) {
        nx = x + dx[dir];
        ny = y + dy[dir];
        if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
        if (isVisited[ny][nx] || map[ny][nx] != '1') continue;
        count++;
        count = group(nx, ny, count);
    }
    return count; 
}

int main() {
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] == '1' && !isVisited[y][x]) {
                region.push_back(group(x, y, 1));
            }
        }
    }

    sort(region.begin(), region.end());

    cout << region.size() << endl;

    for (int i = 0; i < region.size(); i++) {
        cout << region[i] << endl;
    }

    return 0;
}

#endif
