#include "../test-prog.h"
#if (PNUM == lv01-3)
//짝, 홀수 일때 단어별 대소문자 변경
#include <iostream>
#include <string>

using namespace std;

char changeUpper(char ch, int mode) {
    if (mode == 1) {
        if (ch >= 'A' && ch <= 'Z') { ch += 'a' - 'A'; }
    }
    else {
        if (ch >= 'a' && ch <= 'z') { ch -= 'a' - 'A'; }
    }

    return ch;
}

int main() {
    string s = "try hello world";
    string answer;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            count = -1;
        }
        else {
            s[i] = changeUpper(s[i], count % 2);
        }

        answer += s[i];
        count++;
    }

    cout << answer;

    return 0;
}
#endif
