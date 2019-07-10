

#include "../test-prog.h"
#if (PNUM == lv01-6)
//소수 개수 구하기
//반목문의 범위를 조심!
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int answer = 0;
    bool isPrime[1000001];

    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            answer++;
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    cout << answer;

    return 0;
}
/*
초기화하는 로드를 없애기
using namespace std;

bool isNotPrime[1000001];

int solution(int n) {
    int answer = 0;

    for (int i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            answer++;
            for (int j = i * 2; j <= n; j += i) {
                isNotPrime[j] = true;
            }
        }
    }

    return answer;
}
*/
#endif

#include "../test-prog.h"
#if (PNUM == lv01-5)
//문자열을 정수로, 구현버전
#include <iostream>
#include <string>

using namespace std;

int stringToInt(string s) {
	int ret = 0;
	int sign = 1;
	int pos = 1;

	if (s[0] == '-') { sign = -1; }
	for (int i = s.length() - 1; i >= 0; i--) {
		if ('0' <= s[i] && s[i] <= '9') {
			ret += pos * (s[i] - '0');
		}
		pos *= 10;
	}
	return sign * ret;
}
int main() {
	string s = "-1234";
	cout << stringToInt(s);
	return 0;
}
#endif

#include "../test-prog.h"
#if (PNUM == lv01-4)
//시저암호
//char형은 1byte
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n = 25;
	string s = "z";
	string answer = "";
    
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			if (s[i] >= 'a' && s[i] <= 'z') {
				if (s[i] + n > 'z') {
					s[i] -= 26;
					s[i] += n;
				}
				else {
					s[i] += n;
				}
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				if (s[i] + n > 'Z') {
					s[i] -= 26;
					s[i] += n;
				}
				else {
					s[i] += n;
				}
			}
		}
	}
	answer = s;
	cout << answer;
	return 0;
}

#endif

#include "../test-prog.h"
#if (PNUM == lv01-3)
//짝, 홀수 일때 단어별 대소문자 변경
#include <iostream>
#include <string>

using namespace std;

char changeUpper(char ch, int mode) {
    if(mode == 1) {
		if (ch >= 'A' && ch <= 'Z') { ch += 'a' - 'A'; }
	}
	else {
		if (ch >= 'a' && ch <= 'z') { ch -= 'a' - 'A'; }
	}
	
	return ch;
}

int main() {
	string s = "try hello world";
	string answer;
	int count = 0;
    
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			count = -1;
		}
		else {
			s[i] = changeUpper(s[i], count % 2);
		}
		
		answer += s[i];
		count++;
	}

	cout << answer;

	return 0;
}
#endif

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
		answer += arr[i] * pow(10,i);
	}

	cout << answer;

	return 0;
}
#endif

#include "../test-prog.h"
#if (PNUM == lv01-1)
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
