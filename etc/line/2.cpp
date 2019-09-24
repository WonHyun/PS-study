#if 0

// n번째 순열 문제

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    string numString;
    vector<char> nums;
    int k;

    getline(cin, numString);
    cin >> k;

    for (int i = 0; i < numString.length(); i += 2) {
        nums.push_back(numString[i]);
    }

    sort(nums.begin(),nums.end());

    do {
        if (k == 1) {
            for (int i = 0; i < nums.size(); i++) {
                cout << nums[i];
            }
            break;
        }
        k--;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}

#endif
