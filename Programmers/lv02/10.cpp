#include "../test-prog.h"
#if (PNUM == lv02-10)

// 다리를 지나는 트럭

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Truck
{
    int weight, time = 0;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curWeight = 0;
    queue<Truck> wait;
    queue<Truck> truckOnBridge;

    //큐에다 다리길이 개수만큼 padding 해줘서 풀어도 된다!!

    for (int i = 0; i < truck_weights.size(); i++) {
        Truck cur; cur.weight = truck_weights[i];
        wait.push(cur);
    }

    do {
        answer++;
        if (!truckOnBridge.empty() && bridge_length <= (answer - truckOnBridge.front().time)) {
            //다리를 지났으면
            curWeight -= truckOnBridge.front().weight;
            truckOnBridge.pop();
        }

        if (!wait.empty() && (curWeight + wait.front().weight) <= weight) {
            //다리가 무게를 감당할수 있다면
            Truck temp = wait.front(); wait.pop();
            temp.time = answer;
            curWeight += temp.weight;
            truckOnBridge.push(temp);
        }
    } while (!wait.empty() || !truckOnBridge.empty());

    return answer;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    cout << solution(bridge_length, weight, truck_weights);

    return 0;
}

#endif
