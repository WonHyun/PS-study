#include "../test-algo.h"
#if (PNUM == 1845)

// 배부른 돼지

using namespace std;

int main() {
    int n, min = 10, mount;
    char full;
    bool isFail = false;
    cin >> n;

    for (int i = 0; i < n && !isFail; i++) {
        cin >> mount >> full;
        if (full == 'Y') {
            if (min > mount) min = mount;
        }
        else {
            if (mount > min) {
                isFail = true;
                break;
            }
        }
    }

    if (isFail || min == 10) {
        cout << "F";
    }
    else {
        cout << min;
    }

    return 0;
}

#endif
