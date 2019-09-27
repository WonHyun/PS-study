#if 0

// 자리앉기 문제

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> stack;
    int n, cur, max = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (cur) {
            if (stack.empty()) {
                stack.push_back(cur);
            }
            else {
                if (stack.size() + 1 > max) {
                    if ((stack.size() + 1) % 2 != 0) {
                        max = stack.size() + 1;
                    }
                    else {
                        max = stack.size();
                    }
                }
                stack.clear();
                stack.push_back(cur);
            }
        }
        else {
            stack.push_back(cur);
        }
    }

    if (stack.size() + 1 > max) {
        if ((stack.size() + 1) % 2 != 0) {
            max = stack.size() + 1;
        }
        else {
            max = stack.size();
        }
    }

    cout << max / 2;

    return 0;
}

#endif
