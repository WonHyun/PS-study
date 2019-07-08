#include "test-boj.h"
#if (PNUM == 1158)
//조세퍼스 문제
#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if (q.size() > 1) cout << ", ";
		q.pop();
	}

	cout << ">";

	return 0;
}
#endif
