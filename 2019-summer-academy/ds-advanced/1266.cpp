#if 0

#include <iostream>

//qsort + msort 오름차순 정렬 문제

using namespace std;

int n;
int a[30001];
int buf[30001];

// quick sort

void qsort(int s, int e) {
    int p, t, l, temp;
    if (s >= e) return;
    p = e; t = s;
    for (l = s; l < e; l++) {
        if (a[l] < a[p]) {
            temp = a[l];
            a[l] = a[t];
            a[t] = temp;
            t++;
        }
    }

    temp = a[p];
    a[p] = a[t];
    a[t] = temp;

    qsort(s, t - 1);
    qsort(t + 1, e);
}

// merge sort

void msort(int s, int e) {
    if (s >= e) return;
    int mid, i, j, k;
    mid = (s + e) / 2;

    // 1개가 될때 까지 나누기
    msort(s, mid); 
    msort(mid + 1, e);

    // i = 왼쪽영역, j = 오른쪽영역, k = buf의 현재 idx
    i = s; j = mid + 1; k = s;
    while (i <= mid && j <= e) {
        if (a[i] < a[j]) buf[k++] = a[i++];
        else buf[k++] = a[j++];
    }

    while (i <= mid) buf[k++] = a[i++]; // 왼쪽이 마저 채워지지 않은 경우
    while (j <= e) buf[k++] = a[j++]; // 오른쪽이 마저 채워지지 않은 경우

    for (i = s; i <= e; i++) a[i] = buf[i];  // 원본에 옮기기
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //qsort(0, n - 1);
    msort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

#endif
