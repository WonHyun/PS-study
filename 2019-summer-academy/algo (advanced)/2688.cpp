#include "test-algo.h"
#if (PNUM == 2688)

// 치킨배달2, dfs 문제

using namespace std;

int n, m, minDist;

struct pos
{
    int x, y, chk = 0;
};

vector<pos> chick;
vector<pos> home;

int calDist(pos a, pos b) {
    int dist = 0;
    dist += a.x - b.x > 0 ? a.x - b.x : b.x - a.x;
    dist += a.y - b.y > 0 ? a.y - b.y : b.y - a.y;
    return dist;
}

void dfs(int no, int cnt) {
    if (cnt == 0) {
        int tempDist, chickDist = 0;
        int curMin;
        for (int i = 0; i < home.size(); i++) { // 집을 기준으로 가까운 치킨집을 탐색 (반대로 하면 안됨!)
            curMin = 0x7FFFFFFF; // 집마다의 치킨집까지 최단거리
            for (int j = 0; j < chick.size(); j++) {
                if (!chick[j].chk) continue; // 선정되지 않은 치킨집은 스킵
                tempDist = calDist(home[i], chick[j]);
                if (tempDist < curMin) curMin = tempDist;
            }
            chickDist += curMin;
        }
        if (chickDist < minDist) minDist = chickDist;
        return;
    }
    if (no >= chick.size()) return; // 현재 선정할 치킨집이 size를 초과하는 경우 (경계값)
    chick[no].chk++;
    dfs(no + 1, cnt - 1); // 해당 치킨집을 선택하는 경우
    chick[no].chk--;
    dfs(no + 1, cnt); // 해당 치킨집을 선택하지 않는 경우
}

int main() {
    pos temp;
    int input;

    minDist = 0x7FFFFFFF;

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> input;
            if (input == 1) {
                temp.x = x; temp.y = y;
                home.push_back(temp);
            }
            if (input == 2) {
                temp.x = x; temp.y = y;
                chick.push_back(temp);
            }
        }
    }

    dfs(0, m);

    cout << minDist;

    return 0;
}

#endif
