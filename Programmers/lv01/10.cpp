#include "../test-prog.h"
#if (PNUM == lv01-10)

//체육복 문제

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n = 3;
    vector<int> lost = {1,2};
    vector<int> reserve = {2,3};

    //중복제거
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                reserve.erase(reserve.begin() + i, reserve.begin() + i + 1);
                lost.erase(lost.begin() + j, lost.begin() + j + 1);
                break;
            }
        }
    }

    //판단
    int answer = n - lost.size();
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (abs(reserve[i] - lost[j]) < 2) {
                lost[j] = -100;
                answer++;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}

#endif
