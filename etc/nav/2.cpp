#if 0

// 구슬드럼 문제

// 1000*1000이 올수도 있으므로 DP로 풀어야 한다는 말이 있음

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> drum) {
    int answer = 0;
    int n = drum.size(), cx;
    bool meetStar, isValid;


    for (int x = 0; x < n; x++) {
        cx = x;
        meetStar = false;
        isValid = true;
        for (int y = 0; y < n && isValid; y++) {
            while (drum[y][cx] == '>') {
                cx++;
                if (cx >= n) {
                    isValid = false;
                    break;
                }
            }
            while (drum[y][cx] == '<') {
                cx--;
                if (cx < 0) {
                    isValid = false;
                    break;
                }
            }
            if (drum[y][cx] == '*') {
                if (meetStar) {
                    isValid = false;
                    break;
                }
                else meetStar = true;
            }
        }
        if (isValid) answer++;
    }

    return answer;
}

int main() {
    vector<string> drum = {"######",">#*###","####*#","#<#>>#",">#*#*<", "######"};

    cout << solution(drum);

    return 0;
}

#endif
