#include "test-boj.h"
#if (PNUM == 12100)

// 2048 (easy) 문제

//  0, 1, 2, 3 => ( ←, ↓, →, ↑)

#include <iostream>
#include <vector>

using namespace std;

struct board // 현재 상태의 map을 저장하기 위한 구조체
{
    int map[21][21];
};

int n, biggest;
int map[21][21], temp[21][21];
vector<int> com;

void rotate(int cur[][21]) { // 90도 회전, 반시계
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            temp[y][x] = cur[x][n - y - 1];
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cur[y][x] = temp[y][x];
        }
    }
}

void merge(int cur[][21]) { // 위쪽으로 합치는 함수
    // 같은 수 합치기, 수를 한번 합치거나 다른 수가 나오면 break
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!cur[y][x]) continue;
            for (int i = x + 1; i < n; i++) { // 합칠 수 찾기
                if (!cur[y][i]) continue;
                if (cur[y][x] == cur[y][i]) {
                    cur[y][i] = 0;
                    cur[y][x] *= 2;
                    break;
                }
                else break;
            }
        }
    }

    // 숫자 이동, 합치지는 않는다.
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (cur[y][x]) {
                for (int i = x - 1; i >= 0; i--) {
                    if (cur[y][i]) break; // 가려는 곳에 숫자가 있으면 이동하지 않는다.

                    cur[y][i] = cur[y][i + 1];
                    cur[y][i + 1] = 0;
                }
            }
        }
    }
}

int biggestSearch(int cur[][21]) { // 가장 큰 값 찾기
    int big = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (big < cur[y][x]) {
                big = cur[y][x];
            }
        }
    }
    return big;
}

void comp(int cur) { if (cur > biggest) biggest = cur; } // 가장 큰 값을 비교

void dfs(int no, board cur, vector<int> cm) {
    if (no >= 5) { // 최대 5번 이동
        int big = 0;
        for (int i = 0; i < cm.size(); i++) {
            for (int j = 0; j < cm[i]; j++) {
                rotate(cur.map);
            }
            merge(cur.map);
        }
        big = biggestSearch(cur.map);
        comp(big);

        return;
    }
    for (int i = 0; i < 4; i++) {
        cm.push_back(i);
        dfs(no + 1, cur, cm); // 해당 이동을 실행한 경우
        cm.pop_back();
        dfs(no + 1, cur, cm); // 해당 이동을 실행하지 않은 경우
    }
}

int main() {
    board cur;
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cur.map[y][x] = map[y][x];
        }
    }

    dfs(0, cur, com);

    cout << biggest;

    return 0;
}
#endif
