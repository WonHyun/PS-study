#include "../test-prog.h"
#if (PNUM == lv02-5)

//124 나라의 숫자

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    string arr[4] = { "4", "1" , "2" };

    while (n > 0) {
        answer += arr[n % 3];
        if (n % 3 == 0) n--;
        n /= 3;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

int main() {

    for(int i=0;i<20;i++) {
        cout << i << " : " << solution(i) << endl;
    }
   
    return 0;
}

#endif
