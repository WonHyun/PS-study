#include "../test-prog.h"
#if (PNUM == lv03-1)

// 카카오 프랜즈 컬러링 북 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
    int x, y;
};

// 새로운 컬러 영역인지 판단
bool isNew(int num, vector<int> kind) {
    for (int i = 0; i < kind.size(); i++) {
        if (kind[i] == num) return false;
    }
    return true;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    bool isVisited[101][101];

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    int number_of_area = 0, max_size_of_one_area = 0;

    vector<int> answer, kind;

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            isVisited[y][x] = false;
        }
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (!isVisited[y][x] && picture[y][x]) {
                int current_area_size = 0;
                if (isNew(picture[y][x], kind)) number_of_area++;

                queue<pos> q;
                pos temp; temp.x = x; temp.y = y;
                isVisited[y][x] = true;
                current_area_size++;
                q.push(temp);

                while (!q.empty()) {
                    pos cur = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        pos next;
                        next.x = cur.x + dx[dir];
                        next.y = cur.y + dy[dir];
                        if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m) continue;
                        if (isVisited[next.y][next.x] || picture[next.y][next.x] != picture[y][x]) continue;
                        isVisited[next.y][next.x] = true;
                        current_area_size++;
                        q.push(next);
                    }
                }

                if (current_area_size > max_size_of_one_area) max_size_of_one_area = current_area_size;
            }
        }
    }

    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);

    return answer;
}

int main() {
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} };
    vector<int> answer;

    answer = solution(m, n, picture);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
#endif
