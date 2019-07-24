#include "test-algo.h"
#if (PNUM == 1842)

// 소수의 개수, 범위상 최소 최대값 합

using namespace std;

bool isNotPrime[100001];

void calPrime(int b) {
    isNotPrime[0] = true;
    isNotPrime[1] = true;

    for (int i = 2; i <= b; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * 2; j <= b; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}

void swap(int* a, int* b) {
    if (*a > *b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int main() {
    vector<int> v;
    int a, b, count = 0;

    cin >> a >> b;

    swap(&a, &b);
    calPrime(b);
    
    for (int i = a; i <= b; i++) {
        if (!isNotPrime[i]) {
            v.push_back(i);
            count++;
        }
    }

    cout << count << endl;
    if (!v.empty()) {
       cout << v.front() + v.back();
    }
    else {
        cout << 0;
    }

    return 0;
}

#endif
