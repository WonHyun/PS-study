#include "test-boj.h"
#if (PNUM == 14500)

// 테트로미노 문제

// 대칭도 가능한 것을 주의!

#include <iostream>
#include <vector>

using namespace std;

int map[501][501];
int n, m;

vector<vector<vector<int> > > tetro = {
    /*
    ....
    */
    {{1, 1, 1, 1}},
    {{1}, {1}, {1}, {1}},

    /*
    ..
    ..
    */
    {{1, 1}, {1, 1}},

    /*
    .
    .
    ..
    */
    {{1, 0}, {1, 0}, {1, 1}},
    {{1, 1, 1}, {1, 0, 0}},
    {{1, 1}, {0, 1}, {0, 1}},
    {{0, 0, 1}, {1, 1, 1}},
    {{0, 1}, {0, 1}, {1, 1}},
    {{1, 1, 1}, {0, 0, 1}},
    {{1, 1}, {1, 0}, {1, 0}},
    {{1, 0, 0}, {1, 1, 1}},

    /*
    .
    ..
     .
    */
    {{1, 0}, {1, 1}, {0, 1}},
    {{0, 1, 1}, {1, 1, 0}},
    {{0, 1}, {1, 1}, {1, 0}},
    {{1, 1, 0}, {0, 1, 1}},

    /*
    ...
     .
    */
    {{1, 1, 1}, {0, 1, 0}},
    {{0, 1}, {1, 1}, {0, 1}},
    {{0, 1, 0}, {1, 1, 1}},
    {{1, 0}, {1, 1}, {1, 0}}
};

int search() {
    int max = 0, mx, my, cur;

    for (int i = 0; i < tetro.size(); i++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                mx = x + tetro[i][0].size();
                my = y + tetro[i].size();
                if (mx > m || my > n) continue;
                cur = 0;
                for (int j = 0; j < tetro[i].size(); j++) {
                    for (int k = 0; k < tetro[i][j].size(); k++) {
                        if (tetro[i][j][k]) {
                            cur += map[y + j][x + k];
                        }
                    }
                }
                if (cur > max) max = cur;
            }
        }
    }

    return max;
}

int main() {
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }

    cout << search();

    return 0;
}
#endif
