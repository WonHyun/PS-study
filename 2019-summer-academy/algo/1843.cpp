#include "test-algo.h"
#if (PNUM == 1843)

// 숫자 맞추기

using namespace std;

int main() {
    string num, answer;
    int a = 0, b = 0;

    cin >> num >> answer;

    for (int i = 0; i < answer.length(); i++) {
        for (int j = 0; j < num.length(); j++) {
            if (answer[i] == num[j]) {
                if (i == j) a++; // strike
                else b++; // ball
            }
        }
    }

    cout << a << "A" << b << "B";

    return 0;
}

#endif
