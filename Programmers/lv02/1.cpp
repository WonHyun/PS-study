#include "../test-prog.h"
#if (PNUM == lv02-1)

//스킬트리 문제

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
    string skill = "CBD";
    int answer = 0;
    bool isRight = true;
    char *cur;
    
    for (int i = 0; i < skill_trees.size(); i++) {
        isRight = true;
        cur = &skill[0];
        for (int j = 0; j < skill_trees[i].length() && isRight; j++) {
            for (int k = 0; k < skill.length();k++) {
                if (skill_trees[i][j] == skill[k]) {
                    if (skill_trees[i][j] == cur[0]) {
                        cur++;
                        break;
                    }
                    else {
                        isRight = false;
                        break;
                    }
                }
            }
        }
        if (isRight) {
            answer++;
        }
    }

    cout << answer;
    return 0;
}
#endif
