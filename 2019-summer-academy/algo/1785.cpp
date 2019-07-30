#include "test-algo.h"
#if (PNUM == 1785)

// 고기잡이 문제

using namespace std;

struct fish
{
    int x, y;
};

struct net
{
    int height, length;
};

vector<fish> fishes;
vector<net> nets;

int main() {
    
    int n, l, m, max = 0, count = 0;

    cin >> n >> l >> m;

    for (int i = 0; i < m; i++) {
        fish cur;
        cin >> cur.y >> cur.x;
        cur.x--; cur.y--;
        fishes.push_back(cur);
    }

    for (int i = 1; i < l / 2; i++) {
        net cur;
        cur.height = i;
        cur.length = l/2 - i;
        nets.push_back(cur);
    }

    // 물고기가 있는 자리만 쳐보면 됨
    // x, y 전부다

    for (int i = 0; i < nets.size(); i++) {
        for (int y = 0; y < fishes.size(); y++) {
            for (int x = 0; x < fishes.size(); x++) {
                if (fishes[x].x + nets[i].length > n || fishes[y].y + nets[i].height > n) continue;
                count = 0;
                for (int k = 0; k < fishes.size(); k++) {
                    if (fishes[x].x <= fishes[k].x
                        && fishes[y].y <= fishes[k].y
                        && fishes[k].x <= fishes[x].x + nets[i].length
                        && fishes[k].y <= fishes[y].y + nets[i].height) {
                        count++;
                        if (count > max) max = count;
                    }
                }
            }
        }
    }

    cout << max;

    return 0;
}

#endif
