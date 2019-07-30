#include "test-algo.h"
#if (PNUM == 1709)

// 피보나치 수열 문제 

using namespace std;

int arr[41];

// 가지친 재귀함수 버전
int fibonacci(int n) {
    if (arr[n]) return arr[n];
    if (n == 1 || n == 2) return 1;
    return arr[n] = fibonacci(n - 2) + fibonacci(n - 1);
}

//// 일반 재귀함수 버전
//int fibonacci3(int n) {
//    if (n == 1 || n == 2) return 1;
//    return fibonacci(n - 2) + fibonacci(n - 1);
//}

// 반복문 버전
//int fibonacci(int n) {
//    int fibo = 0, first = 1, second = 1;
//    if (n == 1 || n == 2) return 1;
//    for (int i = 3; i <= n; i++) {
//        fibo = first + second;
//        first = second;
//        second = fibo;
//    }
//    return fibo;
//}

int main() {
    int n;
    cin >> n;

    cout << fibonacci(n);

    return 0;
}

#endif
