#include "test-algo.h"
#if (PNUM == 1706)

// 가장 많은 소문자 찾기 문제

using namespace std;

int frequency[26];

int main() {
    int max = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            frequency[s[i] - 'a']++;
            if (max < frequency[s[i] - 'a']) max = frequency[s[i] - 'a'];
        }
    }

    for (int i = 0; i < 26; i++) {
        if (frequency[i] == max) {
            cout << (char)('a' + i);
            break;
        }
    }

    return 0;
}

#endif
