#include "../test-prog.h"
#if (PNUM == lv02-27)

// 숫자의 표현 문제

#include <iostream>
#include <vector>

using namespace std;

int answer;

// 시간초과의 범인
void dfs(int no, int sum, int num, vector<int> list) {
    if (no > num || sum >= num) {
        if (sum == num) answer++;
        return;
    }

    if (list.empty() || list.back() + 1 == no) {
        list.push_back(no);
        dfs(no + 1, sum + no, num, list);
        list.pop_back();
    }
    
    dfs(no + 1, sum, num, list);
}

// 유사 슬라이딩 윈도우
int solution(int n) {
    int sum = 0, cur = 1, answer = 0;

    for (int i = 1; i <= n / 2 + 2; i++) {
        if (sum == n) answer++;
        if (sum > n) {
            while (sum > n) {
                sum -= cur;
                cur++;
            }
            if (sum == n) answer++;
        }
        sum += i;
    }

    return answer + 1;
}

// 홀수인 약수의 개수로도 구할 수 있다
/*
15의 홀수인 약수는 1, 3, 5, 15

1 => 15, 연속하는 하나의 자연수, 15
3 => 15, 5 + 5 + 5 =(-1, 0, +1)> 4 + 5 + 6
5 => 15, 3 + 3 + 3 + 3 + 3 =(-2, -1, 0, +1, +2)> 1 + 2 + 3 + 4 + 5
15 => 15, 연속하는 두 자연수 n / 2. n / 2 + 1 의합 => 7 + 8
*/
int solution2(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i += 2) {
        if (n % i == 0) answer++;
    }

    return answer;
}

// 시간초과
int solution3(int n) {
    vector<int> list;

    dfs(1, 0, n, list);

    return answer;
}

int main() {
    int n = 15;

    cout << solution(n);

    return 0;
}

#endif
