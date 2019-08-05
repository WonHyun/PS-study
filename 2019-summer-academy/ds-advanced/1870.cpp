#if 0

// 바이러스 감염 문제
// 컴퓨터의 개수가 많다면, 인접리스트로 풀어야 할듯?

#include <iostream>

using namespace std;

int mat[101][101];
bool isVisited[101];

int cnt, n, m;

// flood fill

void doInfect(int cur) {
    for (int i = 1; i <= n; i++) {
        if (!isVisited[i] && mat[cur][i]) {
            cnt++;
            isVisited[i] = true;
            doInfect(i);
        }
    }
}

int main() {
    int  cx, cy;

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> cx >> cy;
        mat[cy][cx] = 1;
        mat[cx][cy] = 1;
    }

    isVisited[1] = true;
    doInfect(1);

    cout << cnt;

    return 0;
}

#endif
