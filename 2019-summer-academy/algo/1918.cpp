#include "test-algo.h"

//수식 계산기, 간단 스택버전

using namespace std;

int main(void)
{
    int n, num, temp, answer = 0;
    char op = '+';

    vector<int> st;

    cin >> n;

    for (int i = 0; i < (n * 2) - 1; i++) {
        if (i % 2 == 0) {
            cin >> num;
            switch (op)
            {
            case '-':
                st.push_back(-num);
                break;
            case '*':
                temp = st.back() * num;
                st.pop_back();
                st.push_back(temp);
                break;
            case '/':
                temp = st.back() / num;
                st.pop_back();
                st.push_back(temp);
                break;
            default:
                st.push_back(num);
                break;
            }
        }
        else {
            cin >> op;
        }
    }

    for (int i = 0; i < st.size(); i++) {
        answer += st[i];
    }

    cout << answer;

    return 0;
}
