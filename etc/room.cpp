#if 0
//방안에 남은사람 문제
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, name, status;

    cout << "입력 수 : ";
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> name >> status;
        if (status) {
            v.push_back(name);
        }
        else {
            for (int j = 0; j < v.size(); j++) {
                if (v[j] == name) {
                    v.erase(v.begin() + j);
                    break;
                }
            }
        }
    }

    cout << "방에 남은 사람 : ";

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}

#endif
