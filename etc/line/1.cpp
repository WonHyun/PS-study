#if 0

// 메시지 큐 문제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int calSpendTime(int consumer, queue<int> msg) {
    int totalSpendTime = 0, curTime;
    vector<int> cons(consumer);

    while (!msg.empty()) {
        int curMsg = msg.front(); msg.pop();
        if (consumer) {
            for (int i = 0; i < cons.size(); i++) {
                if (!cons[i]) {
                    cons[i] = curMsg;
                    break;
                }
            }
            consumer--;
        }
        else {
            sort(cons.begin(), cons.end());

            curTime = cons[0];
            totalSpendTime += curTime;

            for (int i = 0; i < cons.size(); i++) {
                cons[i] -= curTime;
            }

            for (int i = 0; i < cons.size(); i++) {
                if (!cons[i]) {
                    cons[i] = curMsg;
                    break;
                }
            }
        }
    }

    sort(cons.begin(), cons.end(), greater<int>());

    totalSpendTime += cons[0];

    return totalSpendTime;
}

int main() {
    int m, c, msg, time;
    queue<int> q;

    cin >> m >> c;

    for (int i = 0; i < m; i++) {
        cin >> msg;
        q.push(msg);
    }

    cout << calSpendTime(c, q);

    return 0;
}

#endif
