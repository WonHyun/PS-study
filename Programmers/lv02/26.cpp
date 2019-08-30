#include "../test-prog.h"
#if (PNUM == lv02-26)

// 가장 큰 정사각형 찾기 문제

// DP 방식으로 접근

/*

각 칸에 있는 숫자를 정사각형를 만들 수 있는 길이로 본다.

자신 이전 3칸이 각각 정사각형을 이루고 있으면 자신을 포함했을 때도 정사각형이 된다.

1 1
1 (2)

1 1 1
1 2 2
1 2 (3)

...

이전 칸들이 만들어낸 정사각형 길이의 최솟값 + 1(자기자신)은
현재 위치에서 만들어 낼 수 있는 정사각형의 최대 길이이다

1 1 1
1 2 2
0 1 (2)

*/

#include <iostream>
#include <vector>

using namespace std;

// 세 수의 최소값 비교
int minComp(int a, int b, int c) {
    int mini = a < b ? a : b;
    return mini < c ? mini : c;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int r = board.size();
    int c = board[0].size();

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (board[y][x]) { // 해당 칸에 1이 있는 경우
                // 이전 칸을 비교하여 현재 위치에서 만들 수 있는 정사각형의 최대길이를 구한다.
                if (x != 0 && y != 0) board[y][x] = minComp(board[y - 1][x], board[y][x - 1], board[y - 1][x - 1]) + 1;
                if (answer < board[y][x]) answer = board[y][x]; // 최대값을 대입
            }
        }
    }

    return answer * answer; // 넓이 반환
}

int main() {
    //vector<vector<int>> board = { {0, 1, 1, 1}, {1, 1, 1, 1},{1, 1, 1, 1},{0, 0, 1, 0} };
    vector<vector<int>> board = { {1, 0}, {0, 0} };

    cout << solution(board);

    return 0;
}

#endif

#if 0

// BFS 방식으로 접근 (시간초과)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int x, y, length;
};

vector<vector<int>> map;
bool isVisited[1001][1001];

int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, 1, 1 };

int r, c;

// 방문 상태 초기화
void init() {
    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            isVisited[y][x] = false;
        }
    }
}

// 정사각형 넓이의 최대값을 반환
int rectSearch(pos start) {
    queue<pos> q;

    q.push(start);

    while (!q.empty()) {
        pos cur = q.front(); q.pop();
        for (int dir = 0; dir < 3; dir++) {
            pos next;
            next.x = cur.x + dx[dir];
            next.y = cur.y + dy[dir];
            if (isVisited[next.y][next.x]) continue; // 방문한 경우 새로 방문할 필요가 없다
            if (next.x >= c || next.y >= r || !map[next.y][next.x]) { // 정사각형을 만들 수 없는 경우
                init();
                return cur.length * cur.length;
            }
            next.length = cur.length + 1;
            q.push(next);
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0, cur;
    r = board.size();
    c = board[0].size();

    map = board;

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (board[y][x]) {
                pos start;
                start.x = x; start.y = y; start.length = 1;
                cur = rectSearch(start);
                if (cur > answer) answer = cur;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> board = { {0, 1, 1, 1}, {1, 1, 1, 1},{1, 1, 1, 1},{0, 0, 1, 0} };

    cout << solution(board);

    return 0;
}

#endif
