#include "../test-prog.h"
#if (PNUM == lv02-22)

// N개의 최소공배수 문제

// N이 3이라면 두개의 최소공배수와 다른 한 수와 최소공배수를 구하면 세 수의 최소공배수가 된다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long gcd(long long a, long long b) {
    long long r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int solution(vector<int> arr) {
    queue<long long> q;
    long long a, b;

    if (arr.size() == 1) return arr[0];

    for (int i = 0; i < arr.size(); i++) {
        q.push(arr[i]);
    }

    while (q.size() > 1) {
        a = q.front(); q.pop();
        b = q.front(); q.pop();
        q.push(a * b / gcd(a, b));
    }

    return q.front();
}

int main() {
    vector<int> arr = { 2, 6, 8, 14 };

    cout << solution(arr);

    return 0;
}

#endif
