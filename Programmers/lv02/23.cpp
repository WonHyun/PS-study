#include "../test-prog.h"
#if (PNUM == lv02-23)

// 최솟값과 최댓값 문제

// 문자열과 정수형 간의 형변환 직접 구현시 실수 할 수 있음, 주의!
// 왠만하면 to_string, stoi를 쓰자

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringToNum(string s) {
    int mul = 1, num = 0;

    if (s[0] == '-') {
        for (int i = s.length() - 1; i > 0; i--) {
            num += mul * (s[i] - '0');
            mul *= 10;
        }
        num *= -1;
    }
    else {
        for (int i = s.length() - 1; i >= 0; i--) {
            num += mul * (s[i] - '0');
            mul *= 10;
        }
    }

    return num;
}

string numToString(int num) {
    string s = "", cur = "";

    if (!num) return "0";
    if (num < 0) {
        s += '-';
        num *= -1;
    }

    while (num != 0) {
        cur += (num % 10) + '0';
        num /= 10;
    }

    for (int i = cur.length() - 1; i >= 0; i--) {
        s += cur[i];
    }

    return s;
}

vector<int> split(string s) {
    vector<int> v;
    string cur = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(stringToNum(cur));
            cur = "";
        }
        else {
            cur += s[i];
        }
    }

    v.push_back(stringToNum(cur));

    return v;
}

// O(n)의 해결법
string solution(string s) {
    int result[2];
    result[0] = 0x7FFFFFFF; // 최솟값
    result[1] = result[0] + 2; // 최댓값
    string temp = "";
    int num = 1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            num *= -1;
        }
        else {
            if (s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
            }
            else {
                num *= stringToNum(temp);
                if (num < result[0]) result[0] = num;
                if (num > result[1]) result[1] = num;
                temp = "";
                num = 1;
            }
        }
    }

    num *= stringToNum(temp);
    if (num < result[0]) result[0] = num;
    if (num > result[1]) result[1] = num;

    return numToString(result[0]) + " " + numToString(result[1]);
}

// 정렬을 이용한 최대 최솟값 찾기, O(nlogn)
// 코드가 단순해짐
string solution2(string s) {
    string answer = "";

    vector<int> v = split(s);

    sort(v.begin(), v.end());

    answer += to_string(v.front()) + ' ' + to_string(v.back());

    return answer;
}

int main() {
    string s = "-1352352 -53523 -63616 0 1237593";

    cout << solution(s);

    return 0;
}

#endif
