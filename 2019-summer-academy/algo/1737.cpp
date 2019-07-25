#include "test-algo.h"
#if (PNUM == 1737)

// 그릇

using namespace std;

int main() {
    int height = 0;
    vector<char> v;
    string s;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (!v.empty()) {
            if (v.back() == s[i]) {
                height += 5;
            }
            else {
                height += 10;
            }
            v.push_back(s[i]);
        }
        else {
            height += 10;
            v.push_back(s[i]);
        }
    }

    cout << height;

    return 0;
}

#endif
