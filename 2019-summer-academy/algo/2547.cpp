#include "test-algo.h"
#if (PNUM == 2547)

// 마름모 문제

#include <math.h>

using namespace std;

long long hexToNum(string s) {
    long long num = 0, pos = 1;
    char hex[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

    for (int i = s.length(); i > -1; i--) {
        for (int j = 0; j < 16; j++) {
            if (s[i] == hex[j]) {
                num += pos * j;
                pos *= 16;
                break;
            }
        }
    }

    return num;
}

int main() {
    int k;
    long long prev;
    double n;
    string s;
    vector<string> rotate;
    vector<string> v;
    vector<long long> answer;

    cin >> n >> k;
    cin >> s;


    rotate.push_back(s);
    for (int i = 1; i < ceil(n / 4); i++) {
        s = s.insert(0, 1, s.at(s.length() - 1));
        s.pop_back();
        rotate.push_back(s);
    }

    // 4각형 나누기

    for (int t = 0; t < ceil(n / 4); t++) {
        for (int i = 0; i < rotate[t].length(); i += ceil(n / 4)) {
            if (i + ceil(n / 4) > rotate[t].length()) { v.push_back(rotate[t].substr(i, rotate[t].length())); }
            else { v.push_back(rotate[t].substr(i, ceil(n / 4))); }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        answer.push_back(hexToNum(v[i]));
    }

    sort(answer.begin(), answer.end(), greater<int>());


    prev = answer[0];
    k--;

    for (int i = 1; i < answer.size(); i++) {
        if (prev == answer[i]) continue;
        k--;
        if (k == 0) {
            cout << answer[i];
        }
        prev = answer[i];
    }

    if (k > 0) {
        cout << answer[answer.size() - 1];
    }

    return 0;
}

#endif
