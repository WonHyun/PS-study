#include "../test-prog.h"
#if (PNUM == lv01-5)
//문자열을 정수로, 구현버전
#include <iostream>
#include <string>

using namespace std;

int stringToInt(string s) {
    int ret = 0;
    int sign = 1;
    int pos = 1;

    if (s[0] == '-') { sign = -1; }
    for (int i = s.length() - 1; i >= 0; i--) {
        if ('0' <= s[i] && s[i] <= '9') {
            ret += pos * (s[i] - '0');
        }
        pos *= 10;
    }
    return sign * ret;
}
int main() {
    string s = "-1234";
    cout << stringToInt(s);
    return 0;
}
#endif
