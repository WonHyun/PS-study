#include "../test-prog.h"
#if (PNUM == lv02-20)

// 라면공장 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0, idx = 0;

    for (int i = 0; i < k; i++) {
        if (idx < dates.size() && i == dates[idx]) {
            pq.push(supplies[idx]);
            idx++;
        }
        if (!pq.empty() && !stock) {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }

    return answer;
}

int main() {
    int stock = 4;
    vector<int> dates = { 4, 10, 15 };
    vector<int> supplies = { 20, 5, 10 };
    int k = 30;

    cout << solution(stock, dates, supplies, k);

    return 0;
}

#endif
