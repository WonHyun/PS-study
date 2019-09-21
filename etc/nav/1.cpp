#if 0

// 이메일 문제

#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int solution(vector<string> emails) {
    string topDomains[3] = { "com", "net", "org" };
    bool haveAt, haveDomainName;
    int answer = 0, j;
    string top;

    for (int i = 0; i < emails.size(); i++) {
        top = "";
        haveAt = false;
        haveDomainName = false;
        for (j = 0; j < emails[i].length(); j++) {
            if (emails[i][j] == '@' && j != 0) {
                haveAt = true;
                break;
            }
            if ((emails[i][j] < 'a' || emails[i][j] > 'z') && emails[i][j] != '.') {
                break;
            }
        }
        if (!haveAt) continue;
        j++;
        for (; j < emails[i].length(); j++) {
            if (emails[i][j] == '.') {
                haveDomainName = true;
                break;
            }
            if (emails[i][j] == '@' || emails[i][j] < 'a' || emails[i][j] > 'z') {
                break;
            }
        }
        if (!haveDomainName) continue;
        j++;
        for (; j < emails[i].length(); j++) {
            top += emails[i][j];
        }
        for (int j = 0; j < 3; j++) {
            if (top == topDomains[j]) {
                answer++;
                break;
            }
        }
    }
    return answer;
}

// 정규식 이용
int solution2(vector<string> emails) {
    int answer = 0;
    regex email("([a-z]|.)+@([a-z])+.(com)|(net)|(org)");

    for (int i = 0; i < emails.size(); i++) {
        if (regex_match(emails[i], email)) answer++;
    }
    
    return answer;
}

int main() {
    vector<string> emails = { "abc.def@x.com", "abc", "abc@defx", "abc@defx.xyz"};

    //cout << solution(emails);
    cout << solution2(emails);

    return 0;
}

#endif
