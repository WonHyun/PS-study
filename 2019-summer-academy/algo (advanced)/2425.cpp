#include "test-algo.h"
#if (PNUM == 2425)

// 양팔저울 문제

using namespace std;

int n, m;
int weights[13];
int balls[8];
bool canCheck[8];

void dfs(int no, int curBall, int sum, int nsum) {
    if (canCheck[curBall] || no > n) return;
    if (sum == nsum) {
        canCheck[curBall] = true;
        return;
    }
    dfs(no + 1, curBall, sum + weights[no], nsum); // 왼쪽에 올리는 경우
    dfs(no + 1, curBall, sum, nsum + weights[no]); // 오른쪽에 올리는 경우
    dfs(no + 1, curBall, sum, nsum); // 아예 올리지 않는 경우
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> balls[i];
    }

    for (int i = 0; i < m; i++) {
        dfs(0, i, balls[i], 0);
    }
    
    for (int i = 0; i < m; i++) {
        if (canCheck[i]) {
            cout << "Y" << " ";
        }
        else {
            cout << "N" << " ";
        }
    }
    
    return 0;
}

#endif
