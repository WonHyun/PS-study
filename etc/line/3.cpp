#if 0

// 화장실 문제

#include <iostream>
#include <vector>

using namespace std;

int timeLine[301];

int main() {
    int n, start, end, max = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            timeLine[j]++;
        }
    }

    for (int i = 0; i < 301; i++) {
        if (timeLine[i] > max) max = timeLine[i];
    }

    cout << max;

    return 0;
}

#endif
