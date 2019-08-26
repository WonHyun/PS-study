#include "test-boj.h"
#if (PNUM == 14888)

// 연산자 끼워넣기 문제
#include <iostream>
#include <vector>

using namespace std;

int nums[12];
int oper[4];

int mini;
int maxi;
int n;

void dfs(int no, vector<int> op) {
    if (no >= n - 1) {
        int sum = nums[0];

        for (int i = 0; i < op.size(); i++) {
            switch (op[i])
            {
            case 0:
                sum += nums[i + 1];
                break;
            case 1:
                sum -= nums[i + 1];
                break;
            case 2:
                sum *= nums[i + 1];
                break;
            case 3:
                sum /= nums[i + 1];
                break;
            }
        }
        if (sum < mini) mini = sum;
        if (sum > maxi) maxi = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (oper[i]) {
            oper[i]--;
            op.push_back(i);
            dfs(no + 1, op);
            op.pop_back();
            oper[i]++;
        }
    }
}

int main() {
    vector<int> op;
    cin >> n;

    mini = 0x7FFFFFFF;
    maxi = 0x7FFFFFFF + 2;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    dfs(0, op);

    cout << maxi << endl;
    cout << mini;

    return 0;
}
#endif
