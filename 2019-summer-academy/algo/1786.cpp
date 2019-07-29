#include "test-algo.h"
#if (PNUM == 1786)

// 창고 다각형 문제

using namespace std;

struct bar
{
    int num, height;
};

bool comp(bar a, bar b) {
    return a.num < b.num;
}

int main() {
    int l, r, n, maxHeight = 0, wide = 0, same = 0, curMax = 0;
    vector<bar> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        bar cur;
        cin >> cur.num >> cur.height;
        if (cur.height > maxHeight) maxHeight = cur.height;
        v.push_back(cur);
    }

    sort(v.begin(), v.end(), comp);

    for (l = 0; v[l].height < maxHeight; l++) {
        same += v[l + 1].num - v[l].num;
        if (curMax < v[l].height) curMax = v[l].height;
        if (curMax < v[l + 1].height) {
            wide += curMax * same;
            same = 0;
        }
    }

    curMax = 0;

    for (r = v.size() - 1; v[r].height < maxHeight; r--) {
        same += v[r].num - v[r - 1].num;
        if (curMax < v[r].height) curMax = v[r].height;
        if (curMax < v[r - 1].height) {
            wide += curMax * same;
            same = 0;
        }
    }

    wide += maxHeight * (v[r].num - v[l].num + 1);

    cout << wide;

    return 0;
}

#endif
