#include "../test-prog.h"
#if (PNUM == lv03-10)

// 디스크 컨트롤러 문제

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct job
{
    int start, time;
};

bool operator<(job a, job b) {
    if (a.time == b.time) {
        return a.start > b.start;
    }
    return a.time > b.time;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0, count = 0, sum = 0, curTime = 0;
    job temp, cur;
    queue<job> q;
    priority_queue<job> pq;

    sort(jobs.begin(), jobs.end());

    for (int i = 0; i < jobs.size(); i++) {
        temp.start = jobs[i][0];
        temp.time = jobs[i][1];
        q.push(temp);
    }

    while (!q.empty() || !pq.empty()) {
        if (pq.empty()) {
            cur = q.front(); q.pop();
            sum += cur.time;
            curTime += cur.time + cur.start - curTime;
            count++;
        }
        else {
            cur = pq.top(); pq.pop();
            sum += cur.time + curTime - cur.start;
            curTime += cur.time;
            count++;
        }
        while (!q.empty() && q.front().start <= curTime) {
            pq.push(q.front()); q.pop();
        }
    }

    return sum / count;
}

int main() {
    //vector<vector<int>> jobs = {{0, 3}, { 1, 9 }, { 2, 6 }};
    //vector<vector<int>> jobs = { {0, 3},{4, 4},{5, 3},{4, 1} };
    vector<vector<int>> jobs = { {0, 3},{1, 9},{500, 6} };

    cout << solution(jobs);

    return 0;
}
#endif
