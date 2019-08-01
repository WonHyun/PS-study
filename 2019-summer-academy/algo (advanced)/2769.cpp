#include "test-algo.h"
#if (PNUM == 2769)

// 구슬고르기1, 조합 문제

using namespace std;

int a[3] = { 2, 5, 7 };
int b[3]; 
int n = 3;  

void dfs(int no) 
{
    if (no >= n) {
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        return;
    }
    b[no] = a[no];
    dfs(no + 1);
    b[no] = 0;
    dfs(no + 1);
}

// count 수만큼 선택하는 경우

void dfs2(int no, int count)
{
    if (no >= n) {
        if (count == 0) {
            for (int i = 0; i < n; i++) {
                if (b[i]) cout << b[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    b[no] = a[no];
    dfs2(no + 1, count - 1);
    b[no] = 0;
    dfs2(no + 1, count);
}

int main(void)
{
    dfs(0); // 모든 조합

    cout << endl;

    dfs2(0, 2); // 2개를 선택하는 경우

    return 0;
}

#endif
