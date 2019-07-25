#include "test-algo.h"
#if (PNUM == 2293)

// 유니크 문제

using namespace std;

struct letter {
    string name;
    vector<int> idx;
};

int main() {
    bool isUniq = true, isFind = false;
    int n;
    string temp;
    letter cur;
    vector<letter> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        isFind = false;
        vector<int> idx;
        idx.push_back(i + 1);
        cin >> temp;
        if (v.empty()) {
            cur.name = temp;
            cur.idx = idx;
            v.push_back(cur);
        }
        else {
            for (int j = 0; j < v.size(); j++) {
                if (v[j].name == temp) {
                    v[j].idx.push_back(i + 1);
                    isUniq = false;
                    isFind = true;
                    break;
                }
            }
            if (!isFind) {
                cur.name = temp;
                cur.idx = idx;
                v.push_back(cur);
            }
        }
    }

    if (isUniq) {
        cout << "unique";
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].idx.size() > 1) {
                cout << v[i].name << " ";
                for (int j = 0; j < v[i].idx.size(); j++) {
                    cout << v[i].idx[j] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}

#endif
