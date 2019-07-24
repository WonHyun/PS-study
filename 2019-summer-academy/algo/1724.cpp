#include "test-algo.h"
#if (PNUM == 1724)

// CD 만들기 문제

using namespace std;

int main() {
    vector<int> v;
    int n, t, len, count, sum = 0;

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> len;
        v.push_back(len);
    }

    sort(v.begin(), v.end());

    for (count = 0; count < v.size(); count++) {
        sum += v[count];
        if (sum > t) break;
    }

    cout << count;

    return 0;
}

#endif
