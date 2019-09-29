#if 0

// 빈도수 우선 큐 문제

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m;

struct number
{
    int num, order;
};

bool operator<(number a, number b) {
    if (m[a.num] == m[b.num]) return a.order > b.order;
    return m[a.num] < m[b.num];
}

struct freQueue {
    vector<number> v;
    bool empty() {
        return !v.size();
    }
    void push(number num) {
        v.push_back(num);
        sort(v.begin(), v.end());
    }
    number top() {
        return v.back();
    }
    void pop() {
        v.pop_back();
        sort(v.begin(), v.end());
    }
};

int main() {
    int n;
    string input;
    vector<int> answer;
    cin >> n;
    cin.ignore();

    //priority_queue<number> pq;
    freQueue pq;

    for (int i = 0; i < n; i++) {
        getline(cin, input);
        if (input[0] == 'e') {
            number cur;
            cur.num = input[input.length() - 1] - '0';
            cur.order = i;
            if (m.find(cur.num) == m.end()) {
                m[cur.num] = 1;
            }
            else {
                m[cur.num]++;
            }
            pq.push(cur);
        }
        if(input[0] == 'd') {
            if (pq.empty()) answer.push_back(-1);
            else {
                answer.push_back(pq.top().num);
                m[pq.top().num]--;
                pq.pop();
            }
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}

#endif
