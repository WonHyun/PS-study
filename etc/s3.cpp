#if 0

// 이벤트 개최일 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> estimates, int k) {
    queue<int> q;
    long long sum = 0, answer = 0;

    for (int i = 0; i < estimates.size(); i++) {
        if (q.size() < k) {
            sum += estimates[i];
            q.push(estimates[i]);
        }
        else {
            sum -= q.front(); q.pop();
            sum += estimates[i];
            q.push(estimates[i]);
        }
        if (sum > answer) answer = sum;
    }

    return answer;
}

int main() {
    vector<int> estimates = { 1, 1, 9, 3, 7, 6, 5, 10 };
    int k = 4;

    cout << solution(estimates, k);

    return 0;
}

#endif
