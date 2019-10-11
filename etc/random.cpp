#if 0

// 배열의 랜덤한 위치에 접근
// 랜덤 별 찍기

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char arr[101][101];
int n, m;

void init() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            arr[y][x] = '.';
        }
    }
}

void printArr() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << arr[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//O(inf)
void solution1(int mount) {
    init();
    int x, y;
    while (mount) {
        x = rand() % m;
        y = rand() % n;
        if (arr[y][x] != '*') {
            arr[y][x] = '*';
            mount--;
        }
    }
    printArr();
}

// O(m*n)
void solution2(int mount) {
    init();
    int rest = n * m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if ((double)(mount) / (double)(rest) >= (double)(rand()) / (double)(RAND_MAX)) {
                arr[y][x] = '*';
            }
        }
    }
    printArr();
}

int main() {
    char input;
    int mount = 0;

    cout << "Type arr size (row, col) :";
    cin >> n >> m;

    cout << "Type choose count (under " << n*m << ") :";
    cin >> mount;

    if (mount > n * m) {
        while (mount > m * n) {
            cout << "Check count range (under " << n * m << ") :";
            cin >> mount;
        }
    }

    srand((unsigned int)time(NULL));

    do {
        cout << "Press any key, if you want exit, press \'e\' :";
        cin >> input;

        switch (input)
        {
        case 'e':
            break;
        default:
            cout << "sol1 : " << endl;
            solution1(mount);

            cout << "sol2 : " << endl;
            solution2(mount);
            break;
        }
    } while (input != 'e');

    return 0;
}

#endif
