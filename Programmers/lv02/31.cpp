#include "../test-prog.h"
#if (PNUM == lv02-31)

// 짝지어 제거하기 문제

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string s)
{
    vector<char> stack;

    for (int i = 0; i < s.length(); i++) {
        if (stack.empty() || stack.back() != s[i]) stack.push_back(s[i]);
        else stack.pop_back();
    }

    return stack.size() ? false : true;
}

int main() {

    string s = "baabaa";

    cout << solution(s);

    return 0;
}

#endif
