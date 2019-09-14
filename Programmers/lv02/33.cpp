#include "../test-prog.h"
#if (PNUM == lv02-33)

// 폰캣몬 문제

#include <iostream>
#include <vector>

using namespace std;

int arr[200001];

int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (!arr[nums[i]]) {
            arr[nums[i]]++;
            if (answer >= nums.size() / 2) break;
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<int> nums = { 3, 3, 3, 2, 2, 4 };

    cout << solution(nums);

    return 0;
}

#endif
