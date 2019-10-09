#include "../test-prog.h"
#if (PNUM == lv03-6)

// 예산 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCheck(vector<int> budgets, int curMax) {
    int sum = 0;
    for (int i = 0; i < budgets.size(); i++) {
        if (budgets[i] < curMax) sum += budgets[i]; // 상한가를 초과하는 값
        else sum += curMax; // 상한가 이하의 값
    }
    return sum;
}

int solution(vector<int> budgets, int M) {
    int answer = 0, s = 0, e, mid;

    sort(budgets.begin(),budgets.end());
    e = budgets[budgets.size() - 1]; // 현재 최대 예산 값

    while (s <= e) {
        mid = (s + e) / 2; // 현재 상한가
        if (maxCheck(budgets, mid) <= M) {
            // 현재 상한가로 예산 할당이 가능한 경우
            s = mid + 1; // 높여 본다
            answer = mid;
        }
        else {
            // 예산 할당이 안되는 경우
            e = mid - 1; // 조금 적게 줘본다
        }
    }

    return answer;
}

int main() {
    vector<int> budgets = { 20, 110, 140, 150 };
    int M = 485;

    cout << solution(budgets, M);

    return 0;
}
#endif
