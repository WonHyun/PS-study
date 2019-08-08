#include "../test-algo.h"
#if (PNUM == 2397)

// 비행기 게임 문제
// 교훈 : 사소한 실수를 조심하자

using namespace std;

struct player
{
    int x, y, score = 0;
    char com = 's';
};

char map[13][6];
char temp[13][6];
player maxScore;

char com[3] = { 'l','m','r'};

void boom(char (*curMap)[6], player plane) {
    int rowMin;
    rowMin = plane.y - 4 < 0 ? 0 : plane.y - 4; // 현재 줄부터 5이내

    for (int y = rowMin; y <= plane.y; y++) {
        for (int x = 0; x < 5; x++) {
            if (curMap[y][x] == 'X') curMap[y][x] = '0';
        }
    }
}

void init() {
    for (int y = 0; y < 13; y++) {
        for (int x = 0; x < 5; x++) {
            temp[y][x] = map[y][x];
        }
    }
}

void dfs(char curMap[][6], player plane) {
    player cur = plane;

    for (int i = 0; i < 3; i++) {
        plane = cur; // 여기도 초기화 하는 것을 주의!
        plane.com = com[i];
        switch (plane.com)
        {
        case 'l':
            plane.x -= 1;
            plane.y -= 1;
            break;
        case 'm':
            plane.y -= 1;
            break;
        case 'r':
            plane.x += 1;
            plane.y -= 1;
            break;
        default:
            break;
        }
        if (plane.x > 4 || plane.x < 0) {
            continue;
        }
        if (plane.y < 0) {
            if (plane.score > maxScore.score) {
                maxScore = cur;
            }
            return; // 끝에 도달시에 return
        }
        if (curMap[plane.y][plane.x] == '*') plane.score += 10;
        if (curMap[plane.y][plane.x] == 'X') plane.score -= 7;

        dfs(curMap, plane);
    }
}

int main(void)
{
    int t;
    cin >> t;

    // start는 13행 3열 == x : 2, y : 12
    player start;
    start.x = 2;
    start.y = 12;

    for (int i = 0; i < t; i++) {
        maxScore.score = 0x7FFFFFFF + 2; // 매 테스트 케이스 마다 초기화 하는 것을 주의할 것 !!!!
        for (int y = 0; y < 13; y++) {
            for (int x = 0; x < 5; x++) {
                cin >> map[y][x];
            }
        }

        // 폭탄을 터뜨리지 않은 경우인데, 폭탄을 터뜨리는 것이 이득이므로 무조건 터뜨리자.
        //dfs(map, start); 

        // 비행기가 있을 수 있는 곳에서 폭탄을 터뜨려 보기
        for (int y = 0; y < 13; y++) {
            for (int x = 0; x < 5; x++) {
                player cur;
                cur.x = x; cur.y = y;
                init();
                boom(temp, cur);
                dfs(temp, start);
            }
        }

        cout << maxScore.score << endl;
    }

    return 0;
}

#endif
