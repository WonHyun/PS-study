#include "test-algo.h"
#if (PNUM == 1835)

// 참외밭 문제

using namespace std;

struct line {
    int dir = 0, length = 0; // 사실 dir은 필요없다
};

int main() {
    vector<line> s, v;
    line max;
    int k, wide = 0, maxIdx = 0;
    int idx, height, first, second, nextIdx;
    cin >> k;

    for (int i = 0; i < 6; i++) {
        line cur;
        cin >> cur.dir >> cur.length;
        v.push_back(cur);
        if (max.length < cur.length) {
            max = cur;
            maxIdx = i;
        }
    }

    first = maxIdx - 1 < 0 ? 5 : maxIdx - 1;
    second = (maxIdx + 1) % 6;

    height = v[first].length > v[second].length ? v[first].length : v[second].length;
    nextIdx = v[first].length < v[second].length ? first: second; // 높이가 아닌 부분 (작은 쪽)

    if ((maxIdx + 1) % 6 == nextIdx) { // 작은 쪽의 방향으로 더해주거나 뺀다
        first = (maxIdx + 2) % 6;
        second = (maxIdx + 3) % 6;
    }
    else {
        first = maxIdx - 2 < 0 ? maxIdx + 3 : maxIdx - 2;
        second = maxIdx - 3 < 0 ? maxIdx + 4 : maxIdx - 3;
    }

    s.push_back(v[first]);
    s.push_back(v[second]);

    wide = max.length * height - (s[0].length * s[1].length);

    cout << k * wide;

    return 0;
}

#endif
