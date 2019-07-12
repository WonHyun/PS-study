#include "../test-prog.h"
#if (PNUM == lv01-11)

//k번째 수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> arr = array;
        sort(arr.begin() + commands[i][0] - 1, arr.begin() + commands[i][1]);
        answer.push_back(arr[commands[i][0] + commands[i][2] - 3]);
    }

    return 0;
}

#endif
