#if 0

// 자외선 피하기 문제

// 우선순위 큐로 탐색하면 자동으로 최소값이 누적

#include <iostream>
#include <queue>

using namespace std;

struct pos
{
    int x, y, sum = 0;
    bool operator()(pos a, pos b) {
        return a.sum > b.sum;
    }
};

int n;
char map[101][102];
bool isVisited[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

priority_queue<pos, vector<pos>, pos> pq;

pos start, answer;

int main(void)
{
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    isVisited[0][0] = true;
    pq.push(start);

    while (!pq.empty()) {
        pos cur = pq.top(); pq.pop();
        isVisited[cur.y][cur.x] = true;

        if (cur.x == n - 1 && cur.y == n - 1) {
            answer = cur;
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            pos next;
            next.x = cur.x + dx[dir];
            next.y = cur.y + dy[dir];
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;
            if (isVisited[next.y][next.x]) continue;
            next.sum = cur.sum + map[next.y][next.x] - '0';
            isVisited[next.y][next.x] = true;
            pq.push(next);
        }
    }

    cout << answer.sum;

    return 0;
}
#endif

#if 0

// 메모리제이션으로 풀이

#include <iostream>
#include <queue>

using namespace std;

struct pos
{
    int x, y;
};

int n;
char map[101][102];
int sum[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pos> q;

pos start, answer;

int main(void)
{
    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
            sum[y][x] = 0x7FFFFFFF;
        }
    }

    q.push(start);
    sum[0][0] = 0;

    while (!q.empty()) {
        pos cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            pos next;
            next.x = cur.x + dx[dir];
            next.y = cur.y + dy[dir];
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n) continue;
            if (sum[next.y][next.x] > sum[cur.y][cur.x] + (map[next.y][next.x] - '0')) {
                sum[next.y][next.x] = sum[cur.y][cur.x] + (map[next.y][next.x] - '0');
                q.push(next);
            }
        }
    }

    cout << sum[n-1][n-1];

    return 0;
}
#endif
