#if 0

// 곤충 카드 모으기 문제

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n, totalCount = 0, totalKind = 0, need = 0, maxCardCount = 0;
    string input;
    map<string, int> m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (m.find(input) == m.end()) {
            m[input] = 1;
            totalKind++;
        }
        else {
            m[input]++;
            if (m[input] > maxCardCount) maxCardCount = m[input];
        }
        totalCount++;
    }

    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second < maxCardCount) {
            need += maxCardCount - iter->second;
        }
    }

    if (need <= 1) {
        cout << "Y" << endl;
        cout << totalCount + need << endl;
        cout << totalKind << endl;
    }
    else {
        cout << "N" << endl;
        cout << totalCount << endl;
        cout << totalKind << endl;
    }

    return 0;
}

#endif
