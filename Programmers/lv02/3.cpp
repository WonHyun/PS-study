#include "../test-prog.h"
#if (PNUM == lv02-3)

//완전탐색 소수 찾기 문제

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime[10000001];

void setPrime() {
    int N = 10000000;

    for (int i = 2; i <= N; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

vector<int> sol1(string numbers) {
    int cur = 0;
    vector<int> num;

    for (int i = 0; i < numbers.length(); i++) {
        do {
            if (numbers[0] != '0') {
                string temp;
                for (int j = 0; j <= i; j++) {
                    temp += numbers[j];
                }
                cur = stoi(temp);
                if (num.empty()) {
                    if (isPrime[cur]) {
                        num.push_back(cur);
                    }
                    
                }
                else {
                    if (num.at(num.size() - 1) != cur) {
                        if (isPrime[cur]) {
                            num.push_back(cur);
                        } 
                    }
                }
            }
        } while (next_permutation(numbers.begin(), numbers.end()));
    }

    return num;
}

int main() {
    string numbers = "1902844";

    setPrime();

    vector<int> result1;
    vector<int> result2;

    result1 = sol1(numbers);
    sort(numbers.begin(),numbers.end()); //뭔가 sort하니까 정답임
    result2 = sol1(numbers);

    if (result1.size() != result2.size()) cout << "다름";

    cout << result1.size() << endl;
    cout << result2.size() << endl;

    return 0;
}

// 순열조합 확인용 코드
//int main() {
//    int answer = 0;
//    int cur = 0;
//
//    string numbers = "011";
//    vector<int> num;
//
//    for (int i = 0; i < numbers.length(); i++) {
//        do {
//            if (numbers[0] != '0') {
//                string temp;
//                for (int j = 0; j <= i; j++) {
//                    temp += numbers[j];
//                }
//                cur = stoi(temp);
//                if (num.empty()) {
//                    num.push_back(cur);
//                }
//                else {
//                    if (num.at(num.size() - 1) != cur) {
//                        num.push_back(cur);
//                    }
//                }
//            }
//        } while (next_permutation(numbers.begin(), numbers.end()));
//    }
//
//    for (int i = 0; i < num.size(); i++) {
//        cout << num[i] << " ";
//    }
//
//    return 0;
//}

// 소수만 나오는지 확인용 코드
//int main() {
//    int answer = 0;
//    int cur = 0;
//
//    string numbers = "1010101";
//    vector<int> num;
//
//    setPrime();
//
//    for (int i = 0; i < numbers.length(); i++) {
//        do {
//            if (numbers[0] != '0') {
//                string temp;
//                for (int j = 0; j <= i; j++) {
//                    temp += numbers[j];
//                }
//                cur = stoi(temp);
//                if (num.empty()) {
//                    if (isPrime[cur]) {
//                        num.push_back(cur);
//                    }
//                    
//                }
//                else {
//                    if (num.at(num.size() - 1) != cur) {
//                        if (isPrime[cur]) {
//                            num.push_back(cur);
//                        } 
//                    }
//                }
//            }
//        } while (next_permutation(numbers.begin(), numbers.end()));
//    }
//
//    for (int i = 0; i < num.size(); i++) {
//        cout << num[i] << " ";
//    }
//
//    return 0;
//}

#endif
