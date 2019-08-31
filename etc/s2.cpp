#if 0

// 온풍기 문제

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> office, int k) {
    int answer = 0, cur;
    int n = office.size();

    for (int y = 0; y <= n - k; y++) {
        for (int x = 0; x <= n - k; x++) {
            cur = 0;
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    cur += office[y + i][x + j];
                }
            }
            if (cur > answer) answer = cur;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> office = {{1, 0, 0, 0}, { 0, 0, 0, 1 }, { 0, 0, 1, 0 }, { 0, 1, 1, 0 }};
    int k = 2;


    cout << solution(office, k);

    return 0;
}

#endif
