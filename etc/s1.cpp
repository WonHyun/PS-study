#if 0

// 전광판 문제

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string phrases, int second) {
    int pos = second % 28;
    string answer = "";

    pos -= phrases.length();

    if (pos > 0) {
        for (int i = pos; i < phrases.length(); i++) {
            answer += phrases[i];
        }
        for (int i = 0; i < pos; i++) {
            answer += "_";
        }
    }
    else {
        pos += phrases.length();
        for (int i = 0; i < phrases.length() - pos; i++) {
            answer += "_";
        }
        for (int i = 0; i < pos; i++) {
            answer += phrases[i];
        }
    }

    return answer;
}

int main() {
    string phrases = "happy-birthday";
    int s = 15;


    cout << solution(phrases, s);

    return 0;
}

#endif
