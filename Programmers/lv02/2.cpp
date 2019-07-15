#include "../test-prog.h"
#if (PNUM == lv02-2)

//탑 문제
//스택 이용해도 되고, reverse 이용해서 풀어도 됨

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<int> heights = { 6, 9, 5, 7, 4 };
    vector<int> answer;
    stack<int> s;

    for (int i = heights.size() - 1; i > -1; i--) {
        bool isReceived = false;
        for (int j = i - 1; j > -1; j--) {
            if (heights[i] < heights[j]) {
                s.push(j + 1);
                isReceived = true;
                break;
            }
        }
        if (!isReceived) {
            s.push(0);
        }
    }

    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }

    for (int i = 0; i < answer.size();i++) {
        cout << answer[i] << " ";
    }
    
    return 0;
}
#endif
