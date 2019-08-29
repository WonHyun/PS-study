#include "../test-prog.h"
#if (PNUM == lv02-24)

// 카펫 문제

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    int div, curBrown, width, height;
    vector<int> answer;

    // red 값의 약수들로 길이가 될 수 있는 경우를 모두 구한다
    // ex) red = 24, brown = 24 라면
    // 24의 약수 1, 2, 3, 4, 6, 8, 12, 24 로 나누어서 가로, 세로의 길이를 구한다
    /*
    bbbbbbbb
    brrrrrrb
    brrrrrrb
    brrrrrrb
    brrrrrrb
    bbbbbbbb

    bbbbbbbbbbbbbb
    brrrrrrrrrrrrb
    brrrrrrrrrrrrb
    bbbbbbbbbbbbbb

    bbbbbbbbbb
    brrrrrrrrb
    brrrrrrrrb
    brrrrrrrrb
    bbbbbbbbbb

    ...
    */

    for (int i = 1; i <= red; i++) {
        if (red % i == 0) {
            div = red / i;
            width = div + 2; // 가로의 길이
            height = i + 2; // 세로의 길이
            if (width < height) break; // 가로보다 세로가 더 커지면 break
            curBrown = div * 2 + (i + 2) * 2; // 필요한 brown의 개수
            if (curBrown == brown) { // 현재 조건과 일치하면 정답이다
                answer.push_back(width);
                answer.push_back(height);
            }
        }
    }

    return answer;
}

int main() {
    vector<int> answer;
    int brown = 24;
    int red = 24;

    answer = solution(brown, red);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}

#endif
