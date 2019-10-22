#include "../test-prog.h"
#if (PNUM == lv03-8)

// 네트워크 문제

#include <iostream>
#include <vector>

using namespace std;

int chk[201]; // 컴퓨터 방문 여부
vector<vector<int>> computer;

void search(int no) {
    chk[no]++; // 방문 체크
    for (int i = 0; i < computer.size(); i++) {
        if (!chk[i] && computer[no][i]) { // 방문안한 노드이고 네트워크가 연결되어 있을 경우
            search(i); // 탐색
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    computer = computers;

    for (int i = 0; i < n; i++) {
        if (!chk[i]) answer++; // 해당 노드가 연결되지 않은 경우 새로운 연결을 생성한다
        search(i);
    }

    return answer;
}

int main() {
    int n = 3;
    vector<vector<int>> computers = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };

    cout << solution(n ,computers);

    return 0;
}
#endif
