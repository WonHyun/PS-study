#include "../test-prog.h"
#if (PNUM == lv02-16)

// 위장 문제

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> m;
    map<string, vector<string>>::iterator iter;
    int answer = 1;

    for (int i = 0; i < clothes.size(); i++) {
        m[clothes[i][1]].push_back(clothes[i][0]);
    }

    for (iter = m.begin(); iter != m.end(); iter++) {
        answer *= ((*iter).second.size() + 1); // 해당 옷을 입는 경우의 수 + 입지 않는 경우의 수 (+1)
    }

    return answer - 1; // 모두 입지 않은 경우를 제외
}

int main() {
    vector<vector<string>> clothes = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };

    cout << solution(clothes);

    return 0;
}

#endif
