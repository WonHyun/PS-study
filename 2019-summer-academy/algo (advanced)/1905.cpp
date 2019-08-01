#include "test-algo.h"
#if (PNUM == 1905)

// 점수더하기, 조합 문제

using namespace std;

int n, k;
int num[21];
int comb[21];
bool isRight;

void disp() {
    for (int i = 0; i < n; i++) {
        if (comb[i]) cout << comb[i] << " ";
    }
    cout << endl;
}

void dfs(int no)
{
    if (no >= n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (comb[i]) sum += comb[i];
        }
        if (sum == k) {
            //disp();
            isRight = true;
        } 
        return;
    }
    comb[no] = num[no];
    dfs(no + 1);
    comb[no] = 0;
    dfs(no + 1);
}

// 가지치기 버전, 그때의 합을 관리한다.

void dfs(int no, int sum)
{
    if (isRight) return;
    if (no >= n) {
        if (sum == k) isRight = true;
        return;
    }
    dfs(no + 1, sum + num[no]);
    dfs(no + 1, sum);
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
