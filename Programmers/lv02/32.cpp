#include "../test-prog.h"
#if (PNUM == lv02-32)

// 행렬의 곱셈 문제

#include <iostream>
#include <vector>

using namespace std;

// a x b 행렬과 b x c 행렬을 곱하면 a x c 행렬이 나온다
/*
1 2
3 4  *  a b
5 6     c d

=>

1a + 2b, 1b + 2d
3a + 4b, 3b + 4d
5a + 6b, 5b + 6d

*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> cal; // 곱해진 행렬의 한 줄

        for (int k = 0; k < arr2[0].size(); k++) { // 곱하는 쪽의 열을 움직인다
            int temp = 0;
            for (int j = 0; j < arr1[0].size(); j++) { // 원래쪽의 열을 움직인다
                temp += arr1[i][j] * arr2[j][k]; // 원래쪽의 열 번호는 곱하는 쪽의 행번호로 적용된다
            }
            cal.push_back(temp);
        }
        answer.push_back(cal);
    }

    return answer;
}

int main() {
    vector<vector<int>> answer;
    vector<vector<int>> arr1 = { {1, 4},{3, 2},{4, 1} };
    vector<vector<int>> arr2 = { {3, 3},{3, 3} };

    answer = solution(arr1, arr2);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

#endif
