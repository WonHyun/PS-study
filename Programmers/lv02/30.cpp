#include "../test-prog.h"
#if (PNUM == lv02-30)

// 땅따먹기 문제

#include <iostream>
#include <vector>

using namespace std;

// land[i][j] + land[i - 1][k] => 현재 값을 선택할 수 있는 경우의 이전값들을 구하고, 합을 구한다
// 이 합의 최대값이 현재 인덱스로 오는 경로의 최대값이 된다

int solution(vector<vector<int>> land)
{
    int answer = 0, curMax = 0, curSum;

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            curMax = 0;
            for (int k = 0; k < land[0].size(); k++) {
                if (j == k) continue;
                curSum = land[i][j] + land[i - 1][k];
                if (curSum > curMax) curMax = curSum;
            }
            land[i][j] = curMax;
        }
    }

    // 마지막 행렬에서 땅을 최대로 먹은 경로의 값을 answer에 대입
    for (int i = 0; i < land[0].size(); i++) {
        if (land[land.size() - 1][i] > answer) answer = land[land.size() - 1][i];
    }

    return answer;
}

int main() {
    //vector<vector<int>> land = { {1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1} };
    vector<vector<int>> land = { {1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}, {1000, 0, 9, 8,} };

    cout << solution(land);

    return 0;
}

#endif
