#include "test-algo.h"
#if (PNUM == 1697)

// 시간외 근무 수당

using namespace std;

class workingMan {
private:
    int pay = 0;
    double workTime = 0;
public:
    double todayStart = 0;
    double todayEnd = 0;

    int getPay() {
        return pay;
    }
    void calWorkTime() {
        double curTime = todayEnd - todayStart - 1.0; // 처음 1시간은 제외
        if (curTime < 0) curTime = 0.0; // 시간외 근무가 1시간 이하 근무면
        if (curTime > 4) curTime = 4.0; // 시간외 근무가 4시간 이상 근무면
        workTime += curTime;
    }
    void doBrainFullOperation() {
        pay += workTime * 10000;
        if (workTime >= 15) {
            pay *= 0.95;
        }
        if (workTime <= 5){
            pay *= 1.05;
        }
    }
};

int main() {
    workingMan minsu;

    for (int i = 0; i < 5; i++) {
        cin >> minsu.todayStart >> minsu.todayEnd;
        minsu.calWorkTime();
    }

    minsu.doBrainFullOperation();
    
    cout << minsu.getPay();

    return 0;
}

#endif
