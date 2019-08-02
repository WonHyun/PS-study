#include "test-algo.h"
#if (PNUM == 3530)

// 못과 액자 문제

using namespace std;

struct picture
{
    int w, h;
};

struct mot {
    int x, y;
};

int n, maximum;
int chk[4];
int map[101][101];
int pic_rec[4];
int dir_rec[4];

mot pin[4];
picture pic[4];

int area_calc() {
    int cnt = 0, h, w, sy, sx, no;
    for (int k = 0; k < n; k++) {
        no = pic_rec[k];
        if (dir_rec[no] == 1) {
            w = pic[no].w;
            h = pic[no].h;
        }
        else {
            w = pic[no].h;
            h = pic[no].w;
        }
        sy = pin[k].y;
        sx = pin[k].x - w / 2;
        for (int y = sy; y < sy + h; y++) {
            for (int x = sx; x < sx + w; x++) {
                map[y][x] = 1;
            }
        }
    }
    for (int y = 0; y <= 100; y++) {
        for (int x = 0; x <= 100; x++) {
            cnt += map[y][x];
            map[y][x] = 0;
        }
    }
    return cnt;
}

void dfs(int no) {
    if (no >= n) {
        int area = area_calc();
        if (area > maximum) maximum = area;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i] == 1) continue;
        chk[i]++;

        pic_rec[no] = i;

        dir_rec[i] = 1;
        dfs(no + 1);

        dir_rec[i] = 2;
        dfs(no + 1);

        chk[i]--;
    }
}

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        mot cur;
        cin >> cur.x >> cur.y;
        pin[i] = cur;
    }

    for (int i = 0; i < n; i++) {
        picture cur;
        cin >> cur.w >> cur.h;
        pic[i] = cur;
    }

    dfs(0);

    cout << maximum;

    return 0;
}

#endif
