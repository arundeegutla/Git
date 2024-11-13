#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1) {}
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (from <= lo && hi <= to) {
            tree[at] = max(tree[at], val);
            return;
        }
        int mid = (lo + hi) >> 1;
        if (from <= mid) update(2 * at, lo, mid, from, to, val);
        if (to > mid) update(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = max(tree[2 * at], tree[2 * at + 1]);
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if (lo > hi) return 0;
        if (from <= lo && hi <= to) return tree[at];
        ll maxx = 0;
        int mid = (lo + hi) >> 1;
        if (from <= mid) maxx = query(2 * at, lo, mid, from, to);
        if (to > mid) maxx = max(maxx, query(2 * at + 1, mid + 1, hi, from, to));
        return maxx;
    }
    ll query(int from, int to) {
        return query(1, 0, n - 1, from, to);
    }
    void update(int from, int to, ll val) {
        update(1, 0, n - 1, from, to, val);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    int maxElem = *(max_element(arr.begin(), arr.end()));
    SegTree increasing(1e6 + 10);
    SegTree decreasing(1e6 + 10);
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        int hereIncrease = decreasing.query(0, arr[i] - 1) + 1;
        int hereDecrease = increasing.query(arr[i] + 1, maxElem + 4) + 1;
        maxx = max({maxx, hereDecrease, hereIncrease});
        increasing.update(arr[i], arr[i], hereIncrease);
        decreasing.update(arr[i], arr[i], hereDecrease);
    }
    cout << maxx << "\n";
}