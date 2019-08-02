#include "../test-algo.h"
//#if (PNUM == 2397)

#if 0

//1
//0X*X0
//00X00
//0XXX0
//00000
//XXXX*
//XXXXX
//00000
//0XXX0
//XX0XX
//*X0X0
//XX0XX
//00000
//00000

// 비행기 게임 문제 

using namespace std;

struct player
{
    int x, y, score = 0, boom = 1;
    char com = 's';
};

char map[13][6];
player maxScore;

char com[4] = { 'l','m','r','b' };

void boom(char (*curMap)[6], player plane) {
    int rowMin, rowMax;
    rowMin = plane.y - 5 < 0 ? 0 : plane.y - 5;

    for (int y = rowMin; y <= plane.y; y++) {
        for (int x = 0; x < 5; x++) {
            if (curMap[y][x] == 'X') curMap[y][x] = '0';
        }
    }
}

void dfs(char curMap[][6], player plane) {
    player cur = plane;

    for (int i = 0; i < 4; i++) {
        plane = cur;
        plane.com = com[i];
        if (plane.boom == 0 && plane.com == 'b') continue;
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
        case 'b':
            if (plane.boom > 0) {
                boom(curMap, plane);
                plane.boom--;
                plane.y -= 1;
            }
            break;
        default:
            break;
        }
        if (plane.x > 5 || plane.x < 0 || plane.y < 0) {
            if (plane.score > maxScore.score) maxScore = cur;
            continue;
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

    player start;
    start.x = 2;
    start.y = 12;

    for (int i = 0; i < t; i++) {
        for (int y = 0; y < 13; y++) {
            for (int x = 0; x < 5; x++) {
                cin >> map[y][x];
            }
        }
        dfs(map, start);
        cout << maxScore.score;
    }

    return 0;
}

#endif
