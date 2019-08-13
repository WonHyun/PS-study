#include "../test-prog.h"
#if (PNUM == lv02-12)

// 큰수 만들기 문제

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string number, int k) {
    int maxIdx = 0;
    char maxVal;
    string answer = "";

    int cnt = number.length() - k; // 만들어질 숫자의 자릿수

    for (int j = cnt; j > 0; j--) {
        maxVal = '0' - 1;
        for (int i = maxIdx; i <= number.length() - j; i++) { // 뽑은 최대값의 인덱스 부터 다음 자릿수 까지 확인
            if (number[i] > maxVal) {
                maxVal = number[i];
                maxIdx = i;
            }
        }
        answer += maxVal; // 해당 자릿 수의 최대값
        number[maxIdx] = '0' - 1;
    }

    return answer;
}

int main() {
    string number = "4177252841";
    //string number = "1231234";

    cout << solution(number, 4);

    return 0;
}

#endif
