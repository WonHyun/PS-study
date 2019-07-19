#include "../test-prog.h"
#if (PNUM == lv02-9)

// 기능개발 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//단순 배열을 이용한 풀이
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    bool isDone = false;

    while (!isDone) {
        isDone = true; //모든 자료가 -1이 된 경우 (모두 처리한 경우)
        for (int i = 0; i < progresses.size(); i++) {
            if (progresses[i] < 0) continue;
            if (progresses[i] >= 100) {
                //release
                int count = 0;
                for (int j = i; j < progresses.size(); j++) {
                    if (progresses[j] < 100) break;
                    progresses[j] = -1;
                    count++;
                }
                answer.push_back(count);
            }
            if (progresses[i] < 100) break;
        }

        for (int i = 0; i < progresses.size(); i++) {
            if (progresses[i] < 0) continue;
            progresses[i] += speeds[i];
            isDone = false;
        } 
    }

    return answer;
}

//큐를 이용한 풀이
vector<int> solution2(vector<int> progresses, vector<int> speeds) {
    int count = 0;
    vector<int> answer;
    queue<int> q;
    
    //작업완료까지 걸리는 일수 계산
    for (int i = 0; i < progresses.size(); i++) {
        // 남은작업량 / 일일작업량 => 완료까지 소요되는 일수
        // 남은작업량 % 일일작업량 => 일일 작업량보다 일이 적게남은 경우 남은양
        int temp = (100 - progresses[i]) % speeds[i]; 
        if (temp == 0)
            q.push((100 - progresses[i]) / speeds[i]);
        else
            q.push((100 - progresses[i]) / speeds[i] + 1); //하루 더 일해야 완료
    }

    while (!q.empty()) {
        int cur = q.front();
        count++;
        q.pop();

        while (!q.empty() && cur >= q.front()) {
            q.pop();
            count++;
        }

        answer.push_back(count);
    }
    return answer;
}

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = {1, 30, 5};
    vector<int> answer;

    answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    cout << endl;
    answer = solution2(progresses, speeds);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}

#endif
