#include "../test-prog.h"
#if (PNUM == lv01-2)
//자릿수 큰걸로 정렬해서 출력
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[10];

int main() {
    long long n = 1234567890;
    long long answer = 0;
    int count = 0;

    for (int i = 0; n != 0; i++) {
        arr[i] = n % 10;
        n /= 10;
        count++;
    }

    sort(arr, arr + count);

    for (int i = 0; i < count; i++) {
        if (arr[i] == 0) { continue; }
        answer += arr[i] * pow(10, i);
    }

    cout << answer;

    return 0;
}
#endif
