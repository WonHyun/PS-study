#include "test-boj.h"
#if (PNUM == 3190)

// 뱀 문제

#include <iostream>
#include <queue>

using namespace std;

// 벽, 뱀이 있는 위치 -1, 사과 1

struct pos
{
    int x, y;
};

struct comend {
    int time;
    char com;  
};

struct snake {
    int dir;
    pos head;
    queue<pos> trace;
    queue<comend> com;
};

int n, k, l, time;
int map[102][102];

// 우 하 좌 상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 시계, 반시계 방향 회전
int turnR[4] = { 1, 2, 3, 0 };
int turnL[4] = { 3, 0, 1, 2 };

// 벽과 뱀 초기 위치 설정
void init() { 
    for (int y = 0; y <= n + 1; y++) {
        for (int x = 0; x <= n + 1; x++) {
            if (x == 0 || y == 0 || x == n + 1 || y == n + 1) map[y][x] = -1;
        }
    }
    map[1][1] = -1;
}

bool move(snake* cur) {
    cur->head.x += dx[cur->dir];
    cur->head.y += dy[cur->dir];
    if (map[cur->head.y][cur->head.x] < 0) return false; // 갈 수 없는 경우
    if (map[cur->head.y][cur->head.x]) { // 사과가 있는 경우
        map[cur->head.y][cur->head.x] = -1;
    }
    else { // 사과가 없는 경우
        map[cur->head.y][cur->head.x] = -1;
        map[cur->trace.front().y][cur->trace.front().x] = 0;
        cur->trace.pop();
    }

    cur->trace.push(cur->head); // 현재 뱀위 위치를 추적

    if (!cur->com.empty() && cur->com.front().time == time) { // 커맨드가 있을 경우
        if (cur->com.front().com == 'D') cur->dir = turnR[cur->dir];
        else cur->dir = turnL[cur->dir];
        cur->com.pop();
    }

    return true;
}

int main() {
    snake start;
    int r, c;

    cin >> n;
    cin >> k;

    init();

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        map[r][c] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++) {
        comend temp;
        cin >> temp.time >> temp.com;
        start.com.push(temp);
    }

    start.dir = 0;
    start.head.x = 1; start.head.y = 1;
    start.trace.push(start.head);

    time++;

    while (move(&start)) time++;

    cout << time;

    return 0;
}
#endif
