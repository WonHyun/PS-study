#include "../test-prog.h"
#if (PNUM == lv02-6)

// 더 맵게 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    // 최소힙의 가장 첫값이 최솟값이다.
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());
    int min, nmin, cur = 0; 
    int count = 0;

    if (!q.empty()) {
        if (q.top() >= K) return 0;
    }

    while (q.top() < K) {
        if (q.size() < 2) return -1;
        min = q.top(); q.pop();
        nmin = q.top(); q.pop();
        cur = min + nmin * 2;
        q.push(cur); //힙에 계산한 값도 다시 넣어줘야 최소값이 계산됨
        count++;
    }

    return count;
}

int main() {
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    //vector<int> scoville = { 12, 3, 9, 2, 10, 1 };
    //vector<int> scoville = { 1, 2 };
    int K = 7;

    cout << solution(scoville, K);

    return 0;
}

#endif
