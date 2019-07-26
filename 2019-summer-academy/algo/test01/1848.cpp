#include "../test-algo.h"
#if (PNUM == 1848)

// 전자레인지, 나누기한 몫으로 구해도 됨

using namespace std;

int main() {
    int a = 0, b = 0, c = 0;
    int t;
    cin >> t;

    while (t >= 300) {
        t -= 300;
        a++;
    }

    while (t >= 60) {
        t -= 60;
        b++;
    }

    while (t >= 10) {
        t -= 10;
        c++;
    }

    if (a == 0 && b == 0 && c == 0 || t > 0) {
        cout << -1;
    }
    else {
        cout << a << " " << b << " " << c;
    }

    return 0;
}

#endif
