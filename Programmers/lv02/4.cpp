#include "../test-prog.h"
#if (PNUM == lv02-4)

//가장 큰 수 문제

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
    int start;
    string answer = "";
    vector<string> numString;

    for (int i = 0; i < numbers.size(); i++) {
        numString.push_back(to_string(numbers[i]));
    }

    sort(numString.begin(), numString.end(), comp);

    for (int i = 0; i < numString.size(); i++) {
        answer += numString[i];
    }

    // zero trim
    if (answer[0] == '0' && answer.length() > 1) {
        for (start = 1; start < answer.length(); start++) {
            if (answer[start] != '0') {break;}
        }
        answer = answer.substr(start - 1, answer.length());
    }

    return answer;
}

int main() {
    //vector<int> numbers = {3, 304, 34, 5, 9, 30, 31, 356, 97, 905};
    vector<int> numbers = { 0, 0, 0, 0 };

    cout << solution(numbers);

    return 0;
}

#endif
