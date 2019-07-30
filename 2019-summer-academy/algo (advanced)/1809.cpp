#include "test-algo.h"
#if (PNUM == 1809)

// 장기 문제

using namespace std;

struct piece
{
    int x, y, move = 0;
};

bool isVisited[101][101];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main() {
    bool isFind = false;
    int n, m, move = 0;
    piece mal, jol;
    queue<piece> q;

    cin >> n >> m;
    cin >> mal.y >> mal.x >> jol.y >> jol.x;
    mal.y--; mal.x--; jol.y--; jol.x--;

    q.push(mal);

    while (!q.empty() && !isFind) {
        piece cur;
        cur = q.front(); q.pop();
        for (int dir = 0; dir < 8; dir++) {
            piece next;
            next.x = cur.x + dx[dir];
            next.y = cur.y + dy[dir];
            next.move = cur.move + 1;
            if (next.x < 0 || next.x > m || next.y < 0 || next.y > n) continue;
            if (isVisited[next.y][next.x]) continue;
            if (next.x == jol.x && next.y == jol.y) {
                move = next.move;
                isFind = true;
                break;
            }
            isVisited[next.y][next.x] = true;
            q.push(next);
        }
    }

    cout << move;

    return 0;
}

#endif
