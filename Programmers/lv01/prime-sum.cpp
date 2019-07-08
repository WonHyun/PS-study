#if 0
#include <iostream>

using namespace std;

bool isPrime[10000001];

int main() {
	long long answer = 0;
	int N;

	cin >> N;

	for (int i = 2; i <= N;i++) {
		isPrime[i] = true;
	}
	//이거 대신에 bool isPrime[10000001] = {false,}; 가능함

	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			answer += i;
			for (int j = i * 2; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	cout << answer;

	return 0;
}
#endif