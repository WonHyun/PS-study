#include "../test-prog.h"
#if (PNUM == lv02-17)

// 구명보트 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, s = 0, e = people.size() - 1;

    sort(people.begin(), people.end());

    while (s <= e) {
        if (people[s] + people[e] <= limit) { // 최소값과 최대값을 합한것으로 탈출이 가능할 경우 (이상적)
            s++;
            e--;
            answer++;
        }
        else { // 해당 최대값은 보트를 따로 제공해야함
            answer++;
            e--;
        }
    }

    return answer;
}

int main() {
    //vector<int> people = { 70, 50, 80, 50 };
    //int limit = 100;

    //vector<int> people = { 30, 40, 40, 70 };
    //int limit = 100;

    vector<int> people = { 70, 70, 70, 70 };
    int limit = 100;

    cout << solution(people, limit);

    return 0;
}

#endif
