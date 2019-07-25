#include "test-algo.h"
#if (PNUM == 1873)

// 회장투표 문제

using namespace std;

int hubo[3][4];
int result[3];

int main() {
    vector<int> v;
    int n, max = 0;
    int vote[3];
    int size = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> vote[0] >> vote[1] >> vote[2];
        for (int j = 0; j < 3; j++) {
            hubo[j][vote[j]]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 4; j++) {
            result[i] += hubo[i][j] * j;
        }
        if (max < result[i]) max = result[i];
    }

    for (int i = 0; i < 3; i++) {
        if (result[i] == max) v.push_back(i);
    }

    // 누가 회장 소리를 내었는가?

    if (v.size() != 1) {
        size = v.size();

        for (int k = 3; k > 1; k--) {
            max = 0;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] != -1) {
                    if (max < hubo[v[i]][k]) max = hubo[v[i]][k];
                }
            }
            for (int i = 0; i < v.size(); i++) {
                // 탈락!
                if (hubo[v[i]][k] < max) {
                    v[i] = -1;
                    size--;
                }
            }
        }
        if (size > 1) {
            // 아무일도 없었다
            cout << 0 << " " << result[0];
        }
        else {
            for (int i = 0; i < v.size(); i++) {
                if (v[i] != -1) {
                    cout << v[i] + 1 << " " << result[v[i]];
                }
            }
        }
    }
    else {
        cout << v[0] + 1 << " " << result[v[0]];
    }

    return 0;
}

#endif
