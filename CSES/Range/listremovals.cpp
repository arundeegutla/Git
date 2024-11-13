#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 1-based tree but 0-based range

struct SegTree {
    int n;
    vector<ll> tree;
    vector<int> arr;
    SegTree(vector<int> arr) : arr(arr), tree(arr.size() * 4 + 1), n(arr.size() + 1) {}
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (from <= lo && hi <= to) {
            tree[at] = val;
            return;
        }
        int mid = (lo + hi) >> 1;
        if (from <= mid) update(2 * at, lo, mid, from, to, val);
        if (to > mid) update(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = tree[2 * at] + tree[2 * at + 1];
    }

    ll count(int at) {
        if (at >= tree.size()) return 0;
        return tree[at];
    }

    ll query(int at, int lo, int hi, int val) {
        if (lo > hi) return -1;
        tree[at] -= 1;

        if (lo == hi) return arr[lo];

        int mid = (lo + hi) >> 1;
        int lCount = count(2 * at);
        if (val <= lCount)
            return query(2 * at, lo, mid, val);
        return query(2 * at + 1, mid + 1, hi, val - lCount);
    }
    ll query(int val) {
        return query(1, 0, n - 1, val);
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
    SegTree tree(arr);
    for (int i = 0; i < n; i++) tree.update(i, i, 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << tree.query(x) << " ";
    }
    cout << "\n";
}