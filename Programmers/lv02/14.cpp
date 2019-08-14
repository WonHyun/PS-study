#include "../test-prog.h"
#if (PNUM == lv02-14)

// 전화번호부 문제

// trie로 푼것은 summer academy에 있음

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true, isSame;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); i++) {
        isSame = true;
        for (int j = 0; j < phone_book[i - 1].length(); j++) {
            if (phone_book[i - 1][j] != phone_book[i][j]) {
                isSame = false;
                break;
            }
        }
        if (isSame) return 0;
    }

    return answer;
}

int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421"};

    cout << solution(phone_book);

    return 0;
}

#endif
