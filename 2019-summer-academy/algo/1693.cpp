#include "test-algo.h"
#if (PNUM == 1693)

// 문자열 찾기 문제

using namespace std;


int main() {
    int koi = 0, ioi = 0;
    string s, cur;
    cin >> s;

    for (int i = 0; i < s.length() - 2; i++) {
        cur = s[i];
        cur += s[i + 1];
        cur += s[i + 2];
        if (cur == "KOI") koi++;
        if (cur == "IOI") ioi++;
    }

    cout << koi << endl;
    cout << ioi << endl;

    return 0;
}

#endif
