#include "../test-prog.h"
#if (PNUM == lv02-7)

// 주식가격 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//2중 for문
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                answer.push_back(j - i);
                break;
            }
            if (j == prices.size() - 1) {
                answer.push_back(j - i);
            }
        }
    }
    return answer;
}

class jugallop {
private:
    int time;
    int price;
    bool isDead;
public:
    jugallop(int time, int price) {
        this->time = time;
        this->price = price;
        isDead = false;
    }

    int getTime() {
        return this->time;
    }

    int getPrice() {
        return this->price;
    }

    int goToHanriver() {
        this->isDead = true;
        //cout << "으아아아아아아아아↘"<< endl;
        return time;
    }
};

//스택버전
vector<int> solution(vector<int> prices, string say) {
    vector<int> answer(prices.size());
    vector<jugallop> stack;

    for (int i = 0; i < prices.size(); i++) {
        if (!stack.empty() && prices[i] < stack.back().getPrice()) {
            while (!stack.empty() && prices[i] < stack.back().getPrice()) {
                answer[stack.back().goToHanriver()] = i - stack.back().getTime();
                stack.pop_back();
            }
        }
        jugallop temp(i, prices[i]);
        stack.push_back(temp);
    }

    while (!stack.empty()) {
        answer[stack.back().goToHanriver()] = prices.size() - stack.back().getTime() - 1;
        stack.pop_back();
    }

    return answer;
}

int main() {
    vector<int> prices = { 1, 2, 3, 2, 3 };
    vector<int> answer;

    answer = solution(prices, "현실반영");

    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "]";

    answer = solution(prices);

    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "]";

    return 0;
}

#endif
