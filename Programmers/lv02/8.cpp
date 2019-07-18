#include "../test-prog.h"
#if (PNUM == lv02-8)

//프린터 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct document
{
    int location, prior;
};

bool operator<(document a, document b) {
    return a.prior < b.prior;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<document> q;
    priority_queue<document> pq;

    for (int i = 0; i < priorities.size(); i++) {
        document cur; cur.location = i; cur.prior = priorities[i];
        q.push(cur);
        pq.push(cur);
    }

    while (!q.empty()) {
        if (q.front().prior < pq.top().prior) {
            //현재 작업의 우선순위가 최고 우선순위보다 작은 경우
            q.push(q.front());
            q.pop();
        }
        else {
            //현재 최고 우선순위 보다 크거나 같은 경우
            answer++;
            if (q.front().location == location) break;
            q.pop();
            pq.pop();
            
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;

    cout << solution(priorities, location);

    return 0;
}

#endif
