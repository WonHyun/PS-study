#include "test-algo.h"
#if (PNUM == 2681)

// 도자기 문제

using namespace std;

int n, m, cnt, temp;
int sand[27];
int chk[27];

int rec[27];

void init() {
    for (int i = 0; i <= 26; i++) {
        chk[i] = 0;
    }
}

// 전역 변수로 중복체크
void dfs(int no, int start) {
    if (no >= m) {
        cnt++;
        return;
    }
    for (int i = start; i < n; i++) {
        if (rec[no] != sand[i]) {
            rec[no] = sand[i];
            dfs(no + 1, i + 1);
        }
    }
    rec[no] = 0;
}

// 지역 변수로 중복체크
void dfs2(int no, int start) {
    int prev = 0;
    if (no >= m) {
        cnt++;
        return;
    }
    for (int i = start; i < n; i++) {
        if (prev != sand[i]) {
            prev = sand[i];
            dfs2(no + 1, i + 1);
        }
    }
}

// 개수로 판단
void dfs3(int no, int start) {
    if (no >= m) {
        cnt++;
        return;
    }
    for (int i = start; i <= 26; i++) { //chk[1]~chk[26] 재료
        if (!chk[i]) continue;
        chk[i]--;
        dfs3(no + 1, i); // 같은 위치 부터 (중복되서 있을수 있으므로)
        chk[i]++;
    }
}

int main(void)
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        init();
        cnt = 0;
        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            cin >> sand[j];
            chk[sand[j]]++;
        }
        sort(sand, sand + n);
        //dfs(0, 0);
        //dfs2(0, 0);
        dfs3(0, 1);
        cout << cnt << endl;
    }

    return 0;
}

#endif
