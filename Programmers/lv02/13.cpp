#include "../test-prog.h"
#if (PNUM == lv02-13)

// 조이스틱 문제

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

// 알파벳을 바꾸는 최소 이동 값
int minCost(char target) {
    int up, down;
    up = target - 'A';
    down = 'Z' - target + 1;
    return up < down ? up : down;
}

// 해당 인덱스 까지 이동하는 최소 값
int calDist(int cur, int target, int len) {
    int f, s;
    f = abs(cur - target);
    s = len - target + cur;
    return min(f, s);
}

int solution(string name) {
    int answer = 0, cursor = 0, next = 0, dist = 0, mini;
    string cur = "";
    
    for (int i = 0; i < name.length(); i++) {
        cur += 'A';
        if (name[i] != 'A') v.push_back(i); // A와 다른, 바꿔야하는 알파벳만 삽입
    }

    while (true) {
        mini = 0x7FFFFFFF;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) continue; // 이미 바꾼 인덱스는 skip
            dist = calDist(cursor, v[i], name.length()); // 해당 인덱스까지 이동거리
            if (dist < mini) { // 최소인 이동거리를 저장
                mini = dist;
                next = i;
            }
        }
        answer += mini; // 이동 횟수
        answer += minCost(name[v[next]]); // 알파벳 변경 횟수
        cur[v[next]] = name[v[next]]; // 변경
        cursor = v[next]; // 다음 위치로 커서 이동
        v[next] = -1; // 바꾼 인덱스는 제외
        if (name == cur) break;
    }

    return answer;
}

int main() {
    string name = "ABABAAAAAAABA";

    cout << solution(name);

    return 0;
}

#endif
