#if 0

// 전화번호 문제 (trie, 다중 트리 구조)

#include <iostream>
#include <string>

using namespace std;

struct trie
{
    int end; // 마지막 링크인지 표시
    trie* next[10]; // 0~9 까지 숫자에 대한 링크
};

trie head;

// 해당 번호가 유효한지 검사
int validate(trie* p, string s) {
    int curNum;
    for (int i = 0; i < s.length(); i++) {
        curNum = s[i] - '0';
        if (p->end) return 0; // 끝 노드라면 유효하지 않음 (이미 이러한 길이의 패턴이 존재한다는 것)
        if (!(p->next[curNum])) return 1;  // 끝 노드가 아니지만, 다음 노드가 존재하지 않으면 unique하다는 것 (유효)
        p = p->next[curNum]; // 다음 노드 탐색
    }

    return 0;
}

void insert(trie* p, string s) {
    int curNum;
    trie* temp;
    for (int i = 0; i < s.length(); i++) {
        curNum = s[i] - '0';
        if (!p->next[curNum]) { // 다음 노드가 존재하지 않으면
            temp = (trie*)calloc(1, sizeof(trie)); // 새로운 trie 생성
            p->next[curNum] = temp; // 링크 연결
        }
        p = p->next[curNum];
    }
    p->end = 1;
}

void init(trie* p) { // trie 초기화
    if (p == 0) return;
    for (int i = 0; i < 10; i++) {
        if (p->next[i]) { // 다음 노드가 존재한다면
            init(p->next[i]);  // 계속탐색
            free(p->next[i]); // 끝노드에 도달후 복귀하면 해당노드 삭제
            p->next[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int t, n;
    bool isValid;

    cin >> t;

    for (int i = 0; i < t; i++) {
        isValid = true;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> input;
            if (!isValid) continue;
            if (!validate(&head, input)) isValid = false;
            insert(&head, input);
        }
        if (isValid) cout << "YES" << endl;
        else cout << "NO" << endl;
        init(&head);
    }

    return 0;
}

#endif
