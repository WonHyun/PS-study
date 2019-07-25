#include "test-algo.h"
#if (PNUM == 1844)

// 덧셈 만들기 문제

using namespace std;

long long stringToNum(string s) {
    long long num = 0, pos = 1;

    for (int i = s.length() - 1; i > -1; i--) {
        num += (s[i] - '0') * pos;
        pos *= 10;
    }

    return num;
}

int main() {
    long long a, b;
    int x, i = 0;
    string s;

    cin >> s >> x;

    for (i = 1; i < s.length(); i++) {
        a = stringToNum(s.substr(0, i));
        b = stringToNum(s.substr(i, s.length()));
        if (a + b == x) break;
    }

    if (i == s.length()) {
        cout << "NONE";
    }
    else {
        cout << stringToNum(s.substr(0, i)) << "+" << stringToNum(s.substr(i, s.length())) << "=" << x;
    }

    return 0;
}

#endif
