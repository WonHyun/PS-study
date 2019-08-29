#include "test-boj.h"
#if (PNUM == 14889)

// 스타트와 링크 문제
#include <iostream>
#include <vector>

using namespace std;

int n, mini;
int chk[21]; // 팀 선정 배열
int arr[21][21];

// 팀 뽑기
void dfs(int no, int start) {
    if (no >= n / 2) {
        int startSum = 0, linkSum = 0, diff = 0;
        vector<int> start, link;

        // 팀 나누기
        for (int i = 0; i < n; i++) {
            if (chk[i]) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        // start 팀의 저력
        for (int i = 0; i < start.size(); i++) {
            for (int j = 0; j < start.size(); j++) {
                startSum += arr[start[i]][start[j]];
            }
        }

        // link 팀의 저력
        for (int i = 0; i < link.size(); i++) {
            for (int j = 0; j < link.size(); j++) {
                linkSum += arr[link[i]][link[j]];
            }
        }

        diff = startSum - linkSum > 0 ? startSum - linkSum : linkSum - startSum;
        if (diff < mini) mini = diff;

        return;
    }
    for (int i = start; i < n; i++) {
        if (chk[i]) continue;
        chk[i]++;
        dfs(no + 1, i + 1);
        chk[i]--;
    }
}

int main() {
    mini = 0x7FFFFFFF;

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }

    dfs(0, 0);

    cout << mini;

    return 0;
}
#endif
