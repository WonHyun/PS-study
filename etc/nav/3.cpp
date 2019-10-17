#if 0

// 프린터 출력 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct document
{
    int num, time, page;
};

bool operator<(document a, document b) {
    if (a.page == b.page) return a.time > b.time;
    return a.page > b.page;
}

vector<int> solution(vector<vector<int>> data) {
    int curTime = 0;
    vector<int> result;
    queue<document> q;
    priority_queue<document> pq;

    for (int i = 0; i < data.size(); i++) {
        document doc;
        doc.num = data[i][0];
        doc.time = data[i][1];
        doc.page = data[i][2];
        q.push(doc);
    }

    pq.push(q.front());
    curTime = q.front().time;
    q.pop();

    while (!q.empty() || !pq.empty()) {
        document cur;
        if (pq.empty()) {
            cur = q.front(); q.pop();
            curTime += cur.time + cur.page - curTime;
        }
        else {
            cur = pq.top(); pq.pop();
            curTime += cur.page;
        }
        result.push_back(cur.num);
        while (!q.empty() && q.front().time <= curTime) {
            pq.push(q.front()); q.pop();
        }
    }

    return result;
}

int main() {
    //vector<vector<int>> data = { {1, 0, 5}, {2, 2, 2}, {3, 3, 1}, {4, 4, 1}, {5, 10, 2} }; // 1, 3, 4, 2, 5
    //vector<vector<int>> data = { {1, 0, 3}, {2, 1, 3}, {3, 3, 2}, {4, 9, 1}, {5, 10, 2} }; // 1, 3, 2, 4, 5
    vector<vector<int>> data = { {1, 2, 10}, {2, 5, 8}, {3, 6, 9}, {4, 20, 6}, {5, 25, 5} }; // 1, 2, 4, 5, 3
    vector<int> result;

    result = solution(data);

    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}

#endif
