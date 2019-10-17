#include "test-boj.h"
#if (PNUM == 15966)

// 군계일학 문제

// 현재, 부분 정답처리 됨

#include <iostream>

using namespace std;

int arr[1000001][2];

int main() {
    int n, num, longest = 0, curLong = 0, curOrder = -1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num][0]++;
        arr[num][1] = i;
    }

    for (int i = 0; i < 1000001; i++) {
        if (arr[i][0] && curOrder < arr[i][1]) {
            curLong++;
            curOrder = arr[i][1];
        }
        else {
            if (curLong > longest) longest = curLong;
            curLong = 0;
            curOrder = -1;
            if (arr[i][0]) {
                curOrder = arr[i][1];
                curLong = 1;
            }
        }
    }

    cout << longest;
    
    return 0;
}

#endif
