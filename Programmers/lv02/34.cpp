#include "../test-prog.h"
#if (PNUM == lv02-34)

// 영어 끝말잇기 문제

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> s;

    answer.push_back(0);
    answer.push_back(0);

    for (int i = 0; i < words.size(); i++) {
        // 이미 언급한 단어일 경우 실패
        for (int j = 0; j < s.size(); j++) {
            if (words[i] == s[j]) {
                answer[0] = i % n + 1;
                answer[1] = i / n + 1;
                return answer;
            }
        }
        // 끝말을 못 이었을 경우 실패
        if (!s.empty() && s.back()[s.back().length() - 1] != words[i][0]) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
        s.push_back(words[i]);
    }

    return answer;
}

int main() {
    int n = 3;
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };

    vector<int> answer;

    answer = solution(n, words);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}

#endif
