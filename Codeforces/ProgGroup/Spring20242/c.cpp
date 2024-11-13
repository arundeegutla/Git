#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

int binSearchLeft(int l, int r) {
    if (r - l == 1) return l;
    int pivot = r;
    int ans = -1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (m == l) break;
        int pivot2 = query(m, pivot);
        if (pivot2 == pivot)
            l = (ans = m) + 1;
        else
            r = m - 1;
    }
    assert(ans != -1);
    return ans;
}

int binSearchRight(int l, int r) {
    if (r - l == 1) return r;
    int pivot = l;
    int ans = -1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (m == l) break;
        int pivot2 = query(pivot, m);
        if (pivot2 == pivot)
            r = (ans = m) - 1;
        else
            l = m + 1;
    }
    assert(ans != -1);
    return ans;
}

int main() {
    int n;
    cin >> n;
    int lo = 1, hi = n;

    int pivot = query(lo, hi);
    if (pivot != 1 && query(lo, pivot) == pivot) {
        cout << "! " << binSearchLeft(lo, pivot) << endl;
    } else {
        cout << "! " << binSearchRight(pivot, hi) << endl;
    }
}