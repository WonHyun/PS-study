#include "test-algo.h"
#if (PNUM == 1800)

// 해밀턴 순환회로 문제 

using namespace std;

int n, mini;
int map[13][13];
int isVisited[13];

// 줄단위로 보면 됨
// ex> 1열 5행에서의 18은 5->1로 가는데에 드는 비용이고, 1행 5열의 20은 1->5로 가는데에 드는 비용이다
// 즉, 1행, 1열의 모든 정보로 가보는 것이 아니라 한 행의 열로만 가보는 것 (개인적으로 착각했었음)

//5
//0 14 4 10 20
//14 0 7 8 7
//4 5 0 7 16
//11 7 9 0 2
//18 7 17 4 0

void dfs(int city, int cnt, int cost) {
    if (cost > mini) return; // 현재 비용이 최소값 보다 크면 시도 안해도 됨
    if (cnt == n - 1) {
        if (map[city][0]) { // 돌아가는 항공편이 있다면
            if (cost + map[city][0] < mini) mini = cost + map[city][0]; // min 비교
        }
        return;
    }

    for (int i = 1; i < n; i++) { // 시작지점은 종료전까지 방문하지 않는다
        if (map[city][i] && !isVisited[i]) { // 해당 도시를 방문하지 않았고, 항공편이 있는 경우
            isVisited[i]++;
            dfs(i, cnt + 1, cost + map[city][i]); // 해당 도시를 방문한다
            isVisited[i]--;
        }
    }
}

int main() {
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    mini = 0x7FFFFFFF;

    dfs(0, 0, 0);

    cout << mini;

    return 0;
}

#endif
