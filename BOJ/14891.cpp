#include "test-boj.h"
#if (PNUM == 14891)

// 톱니바퀴 문제

#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

vector<deque<int>> v;
int chk[4];

void Clock(deque<int> *d) {
    int temp = d->back(); d->pop_back();
    d->push_front(temp);
}

void revClock(deque<int>* d) {
    int temp = d->front(); d->pop_front();
    d->push_back(temp);
}

void doRotate(int no, int dir) {
    if (dir == 1) Clock(&v[no]);
    else revClock(&v[no]);
}

int calScore() {
    int sum = 0, mul = 1;
    for (int i = 0; i < 4; i++) {
        sum += v[i].front() * mul;
        mul *= 2;
    }
    return sum;
}

int main() {
    string s;
    int k, no, dir;

    for (int i = 0; i < 4; i++) {
        deque<int> cur;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            cur.push_back(s[j] - '0');
        }
        v.push_back(cur);
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> no >> dir;
        no--;
        chk[no] = dir;
        for (int j = no; j < 3; j++) {
            if (v[j + 1][6] != v[j][2]) chk[j + 1] = -chk[j];
        }
        for (int j = no; j > 0; j--) {
            if (v[j - 1][2] != v[j][6]) chk[j - 1] = -chk[j];
        }
        for (int j = 0; j < 4; j++) {
            if (chk[j] != 0) {
                doRotate(j, chk[j]);
            }
            chk[j] = 0;
        }
    }

    cout << calScore();

    return 0;
}
#endif
