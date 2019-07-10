#include "../test-prog.h"
#if (PNUM == lv01-4)
//시저암호
//char형은 1byte
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 25;
    string s = "z";
    string answer = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (s[i] + n > 'z') {
                    s[i] -= 26;
                    s[i] += n;
                }
                else {
                    s[i] += n;
                }
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                if (s[i] + n > 'Z') {
                    s[i] -= 26;
                    s[i] += n;
                }
                else {
                    s[i] += n;
                }
            }
        }
    }
    answer = s;
    cout << answer;
    return 0;
}

#endif
