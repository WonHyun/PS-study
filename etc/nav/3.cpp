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

    while (true) {
        if (pq.empty()) {
            document cur = q.front(); q.pop();
            curTime += cur.page;
        }
        
    }

    return result;
}

int main() {
    vector<vector<int>> data = { {1, 0, 5}, {2, 2, 2}, {3, 3, 1}, {4, 4, 1}, {5, 10, 2} };
    vector<int> result;

    result = solution(data);

    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}

#endif
