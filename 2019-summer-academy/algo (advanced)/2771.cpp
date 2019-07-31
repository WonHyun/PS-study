#include "test-algo.h"
#if (PNUM == 2771)

// 구슬 고르기 3 문제

using namespace std;

int a[3] = { 2, 5, 7 }; // 구슬
int b[3];     // 구슬을 담을 상자
int chk[3];     // 체크배열
int N = 3;      // 구슬은 3개

void dfs(int no)
{
    //1] 리턴조건 : 3개를 고른후 인쇄후 리턴
    //2] a배열에서 0부터 N전까지 고르는 모든 경우(단 구슬의 중복을 배제)
    if (no >= N) {
        for (int i = 0; i < N; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (chk[i]) continue;
        b[no] = a[i];
        chk[i]++;
        dfs(no + 1);
        chk[i]--;
    }
}

int main(void)
{
    dfs(0);
    return 0;
}

#endif
