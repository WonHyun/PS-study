#include "test-algo.h"
#if (PNUM == 2679)

//프린터 큐
//프로그래머스 lv02-8 문제랑 같은듯

using namespace std;

struct document
{
    int location, prior;
};

bool operator<(document a, document b) {
    return a.prior < b.prior;
}

int main() {
    int t, n, m, answer;

    cin >> t;

    for (int i = 0; i < t; i++) {
        queue<document> q;
        priority_queue<document> pq;

        answer = 0;

        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            document temp;
            temp.location = j;
            cin >> temp.prior;
            q.push(temp);
            pq.push(temp);
        }

        while (!q.empty()) {
            if (q.front().prior < pq.top().prior) {
                q.push(q.front());
                q.pop();
            }
            else {
                answer++;
                if (q.front().location == m) break;
                q.pop();
                pq.pop();
            }
        }

        cout << answer << endl;
    }

    return 0;
}


#endif
