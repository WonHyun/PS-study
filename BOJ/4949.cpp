#include "test-boj.h"
#if (PNUM == 4949)

// 균형잡힌 세상 문제

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input = "", state = "";
    vector<char> stack;

    while(true) {
        stack.clear();
        state = "yes";
        getline(cin, input);

        if (input == ".") break;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(' || input[i] == '[') {
                stack.push_back(input[i]);
            }
            if (input[i] == ')') {
                if (stack.empty() || stack.back() != '(') {
                    state = "no";
                    break;
                }
                else {
                    stack.pop_back();
                }
            }
            if (input[i] == ']') {
                if (stack.empty() || stack.back() != '[') {
                    state = "no";
                    break;
                }
                else {
                    stack.pop_back();
                }
            }
        }
        if (!stack.empty()) state = "no";
        cout << state << endl;
    }

    return 0;
}
#endif
