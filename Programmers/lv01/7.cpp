#include "../test-prog.h"
#if (PNUM == lv01-7)
//서울에서 김서방 찾기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> seoul;
    seoul.push_back("Jane");
    seoul.push_back("Kim");

    string answer = "";

    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            answer += "김서방은 " + to_string(i) + "에 있다";
        }
    }

    cout << answer;

    return 0;
}
#endif
