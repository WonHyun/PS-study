#include "../test-prog.h"
#if (PNUM == lv03-9)

// 정수 삼각형 문제

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0, maxIdx = triangle.size() - 1;

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0 || j == triangle[i].size() - 1) {
                // 양 끝 원소일 경우
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][0]; // 첫 원소을 참조하여 갱신
                }
                else {
                    triangle[i][j] += triangle[i - 1][j - 1]; // 마지막 원소를 참조하여 갱신
                }
            }
            else {
                // 내려올 수 있는 경우 중 최대값으로 갱신
                triangle[i][j] = max(triangle[i][j] + triangle[i - 1][j - 1], triangle[i][j] + triangle[i - 1][j]);
            }
        }
    }

    for (int i = 0; i < triangle[maxIdx].size(); i++) {
        answer = max(answer, triangle[maxIdx][i]);
    }

    return answer;
}

int main() {
    vector<vector<int>> triangle = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };

    cout << solution(triangle);

    return 0;
}
#endif
