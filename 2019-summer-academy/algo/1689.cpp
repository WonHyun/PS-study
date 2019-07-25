#include "test-algo.h"
#if (PNUM == 1689)

// 문자열 까지의 문자열 문제

#include <regex>

using namespace std;


int main() {
    string n;
    cin >> n;

    regex isChar("[a-z|A-Z]");

    if (regex_match(n, isChar)) {
        if (n[0] < 'a') {
            for (int i = n[0] - 'A'; 'A' + i <= 'Z'; i++) {
                cout << (char)('A' + i);
            }
        }
        else {
            for (int i = 0; i <= n[0] - 'a'; i++) {
                cout << (char)('a' + i);
            }
        }
        
    }
    else {
        cout << "Error";
    }

    return 0;
}

#endif
