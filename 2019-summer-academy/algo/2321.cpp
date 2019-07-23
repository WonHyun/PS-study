#include "test-algo.h"
#if (PNUM == 2321)

//불쾌한 날 문제

using namespace std;

int main() {
    vector<int> v;
    int height;
    int n;
    long long answer = 0;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> height;
        if (v.empty() || v.back() > height) {
            //날 볼수 있는 소들을 더해준다
            answer += v.size();
            v.push_back(height);
        }
        else {
            //나보다 작은 소 다나와
            while (!v.empty() && v.back() <= height) {
                v.pop_back();
            }
            //있으면 ㅇㅈ
            answer += v.size();
            v.push_back(height);
        }
    }
    
    cout << answer;

    return 0;
}

#endif
