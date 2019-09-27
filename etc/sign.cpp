#if 0

// 전광판 광고 문제

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string board[101][101];

int n, w;

void revClockRotate(int start, int end) {
    string temp = board[start][start];

    for (int x = start; x < end; x++) {
        board[start][x] = board[start][x + 1];
    }

    for (int y = start; y < end; y++) {
        board[y][end] = board[y + 1][end];
    }

    for (int x = end; x > start; x--) {
        board[end][x] = board[end][x - 1];
    }

    for (int y = end; y > start; y--) {
        board[y][start] = board[y - 1][start];
    }

    board[start + 1][start] = temp;
}

int main() {
    vector<int> maxRotateCount;
    int cn, cw;

    cin >> n >> w;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }

    if (w) {
        cn = n;

        for (int i = 0; i < n / 2; i++)
        {
            maxRotateCount.push_back(4 * (n - (2 * i)) - 4);
        }

        for (int i = 0; i < maxRotateCount.size(); i++) {
            cw = w < 0 ? -w % maxRotateCount[i] : maxRotateCount[i] - (w % maxRotateCount[i]);
            for (int i = 0; i < cw; i++) {
                revClockRotate(n - cn, cn - 1);
            }
            cn--;
            w *= -1;
        }
    }

    cout << endl;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << board[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

5 -2
강미나 김도연 김세정 김소혜 김청하
유연정 임나영 전소미 정채연 주결경
최유정 강시라 기희현 김나영 김소희
박소연 윤채경 이해인 전소연 정은우
한혜리 강예빈 권은빈 김다니 김서경

3 -777
강미나 김도연 김세정
김소혜 김청하 유연정
임나영 전소미 정채연

*/

#endif
