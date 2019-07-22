#include "test-algo.h"
#if (PNUM == 2318)

//카드 건네기

using namespace std;

int main() {
    int n, count;
    vector<int> answer;
    queue<int> q;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }


    while (!q.empty()) {
        count = q.back() / 2;

        for (int j = 0; j < count; j++) {
            q.push(q.front());
            q.pop();
        }

        answer.push_back(q.front());
        q.pop();
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}


#endif
