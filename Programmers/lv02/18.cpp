#include "../test-prog.h"
#if (PNUM == lv02-18)

// 숫자야구 문제

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 0 숫자 1 스트라이크 2 볼

int chk[10], num[3], answer;

// 질문을 전역변수로 다루기 위한 변수
vector<vector<int>> require;

// 스트라이크, 볼 개수를 판단하는 함수
void calScore(string cur, string comp, int* cs, int* cb) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (cur[i] == comp[j]) {
                if (j == i) *cs += 1;
                else *cb += 1;
            }
        }
    }
}

// 현재 조합과 질문을 비교하는 함수
void valid() {
    string comp, cur;
    int cs, cb;

    for (int i = 0; i < 3; i++) {
        cur += num[i] + '0';
    }

    for (int i = 0; i < require.size(); i++) {
        cs = 0; cb = 0;
        comp = to_string(require[i][0]);
        calScore(cur, comp, &cs, &cb);
        if (cs != require[i][1] || cb != require[i][2]) return;
    }
    answer++;
}

// 숫자를 뽑는 함수
void dfs(int no) {
    if (no >= 3) {
        valid();
        return;
    }

    for (int i = 1; i < 10; i++) {
        if (chk[i]) continue;
        chk[i]++;
        num[no] = i;
        dfs(no + 1);
        chk[i]--;
        num[no] = 0;
    }
}

int solution(vector<vector<int>> baseball) {
    require = baseball;

    dfs(0);

    return answer;
}

int main() {

    vector<vector<int>> baseball = { {123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1} };

    cout << solution(baseball);

    return 0;
}

#endif
