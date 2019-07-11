#include "../test-prog.h"

#if (PNUM == lv01-8)

//문자열 마음대로 정렬 문제

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(string* a, string* b) {
    string temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int n = 2;

    vector<string> strings{ "abz", "aby", "abzy", "aba" };
    vector<string> correct{ "aba", "aby", "abz", "abzy" };

    //vector<string> strings{ "abzcd", "cdzab", "abzfg", "abzaa", "abzbb", "bbzaa" };
    //vector<string> correct{ "abzaa", "abzbb", "abzcd", "abzfg", "bbzaa", "cdzab" };

    //vector<string> strings{ "abce", "abcd", "cdx" };
    //vector<string> correct{ "abcd", "abce", "cdx" };
    
    for (int i = 0; i < strings.size(); i++) {
        for (int j = i + 1; j < strings.size(); j++) {
            if (strings[i][n] > strings[j][n]) {
                swap(&strings[i], &strings[j]);
            }
            if (strings[i][n] == strings[j][n]) {
                int length = strings[i].length() > strings[j].length() ? strings[i].length() : strings[j].length();
                for (int k = 0; k < length; k++) {
                    if (strings[i][k] > strings[j][k]) {
                        swap(&strings[i], &strings[j]);
                        break;
                    }
                    else if (strings[i][k] < strings[j][k]) {
                        break;
                    }
                }
            }
        }
    }

   if (strings == correct) {
        cout << "O";
    }
    else {
        cout << "X";
    }

    return 0;
}

#endif

#if (PNUM == lv01-8-sol2)

//좀더 심플한 방법

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int i;

bool comp(string a, string b) {
    return a[i] == b[i] ? a < b : a[i] < b[i];
}

int main() {
    int n = 2;
    i = n;

    vector<string> strings{ "abzcd", "cdzab", "abzfg", "abzaa", "abzbb", "bbzaa" };
    vector<string> correct{ "abzaa", "abzbb", "abzcd", "abzfg", "bbzaa", "cdzab" };

    sort(strings.begin(),strings.end(),comp);

    if (strings == correct) {
        cout << "O";
    }
    else {
        cout << "X";
    }

    return 0;
}

#endif
