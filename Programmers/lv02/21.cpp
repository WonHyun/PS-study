#include "../test-prog.h"
#if (PNUM == lv02-21)

// 소수만들기 문제

#include <iostream>
#include <vector>

using namespace std;

bool isNotPrime[100001];
int answer;

void dfs(int no, vector<int> nums, int sum, int start) {
    if (no >= 3) {
        if (!isNotPrime[sum]) answer++;
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        dfs(no + 1, nums, sum + nums[i], i + 1);
    }
}

void init() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i <= 100000; i++) {
        for (int j = i * 2; j <= 100000; j += i) {
            isNotPrime[j] = true;
        }
    }
}

int solution(vector<int> nums) {
    init();

    dfs(0, nums, 0, 0);

    return answer;
}

int main() {
    vector<int> nums = { 1,2,7,6,4 };

    cout << solution(nums);

    return 0;
}

#endif
