#include "test-algo.h"
#if (PNUM == 1956)

// 주사위 던지기1, 중복 조합 문제

using namespace std;

int n, m;

int dice[7];
int chk[7];

// 중복 순열

void dfs1(int no) {
    if (no >= n) {
        for (int i = 0; i < n; i++) {
            if(dice[i]) cout << dice[i] << " ";  
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= 6; i++) {
        dice[no] = i;
        dfs1(no + 1);
        dice[no] = 0;
    }
}

// 중복 조합 제외 1,1,2 == 1,2,1 == 2,1,1

void dfs2(int no, int start) {
    if (no >= n) {
        for (int i = 0; i < n; i++) {
            if (dice[i]) cout << dice[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= 6; i++) {
        dice[no] = i;
        dfs2(no + 1, i);
    }
}

// 중복 비허용 순열 (일반 순열)

void dfs3(int no) {
    if (no >= n) {
        for (int i = 0; i < n; i++) {
            if (dice[i]) cout << dice[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= 6; i++) {
        if (chk[i]) continue;
        chk[i]++;
        dice[no] = i;
        dfs3(no + 1);
        chk[i]--;
        dice[no] = 0;
    }
}

// 중복 배제 조합 1,1,1 (x)

void dfs4(int no, int start) {
    if (no >= n) {
        for (int i = 0; i < n; i++) {
            if (dice[i]) cout << dice[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= 6; i++) {
        dice[no] = i;
        dfs4(no + 1, i + 1);
    }
}

int main(void)
{
    cin >> n >> m;

    switch (m)
    {
    case 1:
        dfs1(0);
        break;
    case 2:
        dfs2(0, 1);
        break;
    case 3:
        dfs3(0);
        break;
    case 4:
        dfs4(0, 1);
    default:
        break;
    }

    return 0;
}

#endif
