#include "../test-prog.h"
#if (PNUM == lv02-11)

// 쇠막대기 문제

#include <iostream>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    vector<char> stack;
    bool isRazer = false;

    for (int i = 0; i < arrangement.length(); i++) {
        if (arrangement[i] == '(') {
            stack.push_back(arrangement[i]);
            isRazer = true;
        }
        else {
            if (!stack.empty()) {
                stack.pop_back();
            }
            if (isRazer) {
                //레이저 bal4
                answer += stack.size();
                isRazer = false;
            }
            else {
                //쇠막대가 끝나는 경우
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    string arrangement = "()(((()())(())()))(())";

    cout << solution(arrangement);

    return 0;
}

#endif
