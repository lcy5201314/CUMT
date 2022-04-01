#include <iostream>

using namespace std;

const int maxn = 500010;
int a[maxn];
int aux[maxn];
long long sum;
int n;

void merge(int l, int mid, int r) {
    int i = l;
    int j = mid+1;
    int end1 = mid;
    int end2 = r;

    for (int t = l; t <= r; t++) {
        aux[t] = a[t];
    }

    for (int t = l; t <= r; t++) {
        if (j > end2) {
            a[t] = aux[i++];
        } else if (i > end1) {
            a[t] = aux[j++];
        } else if (aux[i] > aux[j]) {
            sum += mid-i+1;
            a[t] = aux[j++];
        } else if (aux[i] <= aux[j]) {
            a[t] = aux[i++];
        }
    }
}

void msort(int l, int r) {
    if (l < r) {
        int mid = (l + r)  / 2;
        msort(l, mid);
        msort(mid+1, r);
        merge(l, mid, r);
    }
}


int main(void) {
    while (cin >> n && n) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        msort(0, n-1);
        cout << sum << endl;
    }

    return 0;
}
