#include "test-algo.h"
#if (PNUM == 3047)

//조깅 문제

using namespace std;

int main() {
    int N, pos, speed, cur, answer = 0;
    vector<int> st;

    cin >> N;
    for (int i = 0; i < N;i++) {
        cin >> pos >> speed;
        st.push_back(speed);
    }

    while (!st.empty()) {
        cur = st.back(); st.pop_back();
        while (!st.empty() && st.back() > cur) {
            st.pop_back();
        }
        answer++;
    }

    cout << answer;

    return 0;
}
#endif
