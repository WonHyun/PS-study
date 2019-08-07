#if 0

// 지하철 문제

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct person {
    int time = 0;
    vector<int> route = { 0 };
    bool operator()(person a, person b) {
        return a.time > b.time;
    }
};

int n, m;

int map[101][101];

priority_queue<person, vector<person>, person> pq;

int main(void)
{
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    for (int x = 0; x < n; x++) {
        if (map[0][x]) {
            person temp;
            temp.time = map[0][x];
            temp.route.push_back(x);
            pq.push(temp);
        }
    }

    while (!pq.empty()) {
        person cur = pq.top(); pq.pop();
        if (cur.route.back() == m - 1) {
            cout << cur.time << endl;
            for (int i = 0; i < cur.route.size(); i++) {
                cout << cur.route[i] + 1 << " ";
            }
            break;
        }
        for (int i = 0; i < n; i++) { // 모든 값을 탐색해야함
            person next = cur;
            if (!map[cur.route.back()][i]) continue;
            next.time += map[cur.route.back()][i];
            next.route.push_back(i);
            pq.push(next);
        }
    }

    return 0;
}
#endif
