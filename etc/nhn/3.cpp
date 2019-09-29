#if 0

// 사탕 획득 카드 게임

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct player {
    int num, score;
    vector<int> follower;
};

vector<player> p;
vector<int> done;

void followerPropagation(int start) {
    for (int i = 0; i < done.size(); i++) {
        if (done[i] == start) return;
    }
    p[start].score++;
    for (int i = 0; i < p[start].follower.size(); i++) {
        followerPropagation(p[start].follower[i]);
    }
}

int main() {
    int n, prev, next, cardOwner = 0;
    string input;
    cin >> n;

    for (int i = 0; i < n; i++) {
        player temp;
        temp.num = i;
        temp.score = 0;
        p.push_back(temp);
    }

    cin.ignore();
    getline(cin, input);

    for (int i = 0; i < input.length(); i += 2) {
        done.clear();
        switch (input[i]) {
        case 'A':
            followerPropagation(cardOwner);
            break;
        case 'J':
            prev = cardOwner - 1 >= 0 ? cardOwner - 1 : n - 1;
            next = (cardOwner + 1) % n;
            followerPropagation(prev);
            followerPropagation(next);
            break;
        case 'Q':
            for (int j = 0; j < p.size(); j++) p[j].score++;
            break;
        case 'K':
            p[cardOwner].follower.push_back(input[i + 2] - '0');
            i += 2;
            break;
        }
        cardOwner = (cardOwner + 1) % n;
    }

    for (int i = 0; i < p.size(); i++) {
        cout << p[i].score << " ";
    }

    return 0;
}

#endif
