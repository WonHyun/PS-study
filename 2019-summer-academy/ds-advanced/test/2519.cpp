#if 0

// 못생긴 수2 문제

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<long long, vector<long long>, greater<long long>> pq; // 최소 힙
vector<long long> v;

int main() {
    long long cur;

    pq.push(1);
    v.push_back(0);
    v.push_back(1);

    while (v.size() < 1501) {
        cur = pq.top();
        
        if (v.back() != cur) {
            v.push_back(cur);
        }

        // 2 or 3 or 5 의 소인수를 가지는 수는 그의 배수이다
        pq.push(cur * 2);
        pq.push(cur * 3);
        pq.push(cur * 5);

        while (cur == pq.top()) pq.pop();
    }

    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << v[n] << endl;
    }
    
    return 0;
}

#endif
