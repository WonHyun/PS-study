#include "test-algo.h"
#if (PNUM == 1749)

// 100 만드는 숫자 찾기

using namespace std;

int arr[9];

int main() {
    int sum = 0, temp = 0;
    int a = 0, b = 0;
    bool isFind = false;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 9);

    for (int i = 0; i < 9 && !isFind; i++) {
        temp = sum;
        temp -= arr[i];
        for (int j = 0; j < 9; j++) {
            if (temp - arr[j] == 100) { // 100이 안되게 하는 두수를 찾았으면
                a = i;
                b = j;
                isFind = true;
                break;
            }
        }
    }

    arr[a] = -1;
    arr[b] = -1;

    for (int i = 0; i < 9; i++) {
        if (arr[i] != -1) {
            cout << arr[i] << endl;
        }
    }
    
    return 0;
}

#endif
