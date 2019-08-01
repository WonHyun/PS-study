#include "test-algo.h"
#if (PNUM == 1905)

// 점수더하기, 조합 문제

using namespace std;

int n, k;
int num[21];
int comb[21];
bool isRight;

void dfs(int no)
{
    if (no >= n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (comb[i]) sum += comb[i];
        }
        if (sum == k) isRight = true;
        return;
    }
    comb[no] = num[no];
    dfs(no + 1);
    comb[no] = 0;
    dfs(no + 1);
}

int main(void)
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        isRight = false;
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> num[j];
        }
        dfs(0);
        if (isRight) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

#endif
