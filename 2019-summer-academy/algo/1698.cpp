#include "test-algo.h"
#if (PNUM == 1698)

// 케이크 자르기 문제

using namespace std;

void swap(int* a, int* b) {
    if (*a > * b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int main() {
    int a, b, x, y;
    bool isCrossed = false;

    cin >> a >> b >> x >> y;

    swap(&a, &b);
    swap(&x, &y);

    if (a < x) {
        if (x < b && b < y) isCrossed = true;
    }
    else {
        if (a < y && y < b) isCrossed = true;
    }

    if (isCrossed) {
        cout << "cross";
    }
    else {
        cout << "not cross";
    }
    
    return 0;
}

#endif
