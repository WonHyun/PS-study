#include "../test-prog.h"
#if (PNUM == lv02-25)

// 타겟 넘버 문제

#include <iostream>
#include <vector>

using namespace std;

int answer;
int t;
vector<int> num;

void dfs(int no) {
    if (no >= num.size()) {
        int sum = 0;
        for (int i = 0; i < num.size(); i++) sum += num[i];
        if (sum == t) answer++;
        return;
    }

    dfs(no + 1); // 해당 수를 더하는 경우
    num[no] *= -1;
    dfs(no + 1); // 해당 수를 빼는 경우
    num[no] *= -1;
}

int solution(vector<int> numbers, int target) {
    num = numbers;
    t = target;

    dfs(0);

    return answer;
}

int main() {
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    int target = 3;

    cout << solution(numbers, target);

    return 0;
}

#endif
