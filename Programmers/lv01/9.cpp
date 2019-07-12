#include "../test-prog.h"
#if (PNUM == lv01-9)

//두수 사이의 합

#include <iostream>
#include <math.h>

using namespace std;

void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void answer1(int a, int b) {
    long long answer = 0;

    if (a > b) { swap(&a, &b); }
    for (int i = a; i <= b; i++) {
        answer += i;
    }

    cout << answer << endl;
}

void answer2(int a, int b) {
    long long answer = 0;

    answer = ((long long)(a + b) * (abs(a - b) + 1)) / 2;

    cout << answer << endl;
}

int main() {
    int a, b;
    cin >> a >> b;

    answer1(a,b);
    answer2(a,b);

    return 0;
}

#endif
