#include "../test-prog.h"
#if (PNUM == lv01-12)

//완주하지 못한 선수

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++) {
        if (completion[i] != participant[i]) {
            return participant[i];
        }
    }

    return participant[participant.size() - 1];
}

int main() {
    string answer = "";
    vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> completion = {"josipa", "filipa", "marina", "nikola"};

    cout << solution(participant, completion);

    return 0;
}

#endif
