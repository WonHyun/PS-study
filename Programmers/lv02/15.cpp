#include "../test-prog.h"
#if (PNUM == lv02-15)

// H-Index 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬

    for (int i = 0; i < citations.size(); i++) {
        if (i >= citations[i]) { // 해당 논문의 인용횟수보다 현재 인덱스가 크거나 같으면
            return answer = i; // 해당 인덱스가 h - index
        }
    }

    return citations.size(); // 다 돌아도 찾지 못하는 경우 논문의 수를 return
}

int main() {
    vector<int> citations = { 3, 0, 6, 1, 5 };
    //vector<int> citations = { 10, 100 };
    //vector<int> citations = { 6, 6, 6, 6, 6, 6 };
    //vector<int> citations = { 0, 0, 0, 0, 0 };

    cout << solution(citations);

    return 0;
}

#endif
