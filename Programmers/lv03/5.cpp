#include "../test-prog.h"
#if (PNUM == lv03-5)

// 이중 우선순위 큐 문제

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class doublePriorityQueue {
private:
    deque<int> dq;
public:
    void enqueue(int data) {
        dq.push_back(data);
        sort(dq.begin(), dq.end());
    }
    int maxDequeue() {
        int ret = dq.back();
        dq.pop_back();
        return ret;
    }
    int minDequeue() {
        int ret = dq.front();
        dq.pop_front();
        return ret;
    }
    bool isEmpty() {
        return dq.empty();
    }
};

vector<int> solution(vector<string> operations) {
    string sub;
    doublePriorityQueue dpq;
    vector<int> answer(2);
    answer[0] = answer[1] = 0;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            sub = operations[i].substr(2, operations[i].length() - 1);
            dpq.enqueue(stoi(sub));
        }
        else {
            if (!dpq.isEmpty()) {
                if (operations[i][2] == '-') {
                    dpq.minDequeue();
                }
                else {
                    dpq.maxDequeue();
                }
            }
        }
    }

    if (!dpq.isEmpty()) {
        answer[0] = dpq.maxDequeue();
        if (dpq.isEmpty()) {
            answer[1] = answer[0];
        }
        else {
            answer[1] = dpq.minDequeue();
        }
    }

    return answer;
}

int main() {
    vector<string> operation = { "I 7", "I 5", "I -5", "D -1" };
    vector<int> answer;

    answer = solution(operation);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}

#endif
