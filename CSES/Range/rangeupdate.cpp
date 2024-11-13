#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1-based tree but 0-based range
struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1), lazy(n * 4 + 1) {}
    void push(int at, int lo, int hi) {
        if (lo != hi) {
            lazy[2 * at + 1] += lazy[at];
            lazy[2 * at] += lazy[at];
        }
        tree[at] += (hi - lo + 1) * lazy[at];
        lazy[at] = 0;
    }
    void update(int at, int lo, int hi, int from, int to, ll val) {
        push(at, lo, hi);
        if (from <= lo && hi <= to) {
            lazy[at] += val;
            push(at, lo, hi);
            return;
        }
        int mid = (lo + hi) >> 1;
        if (from <= mid) update(2 * at, lo, mid, from, to, val);
        if (to > mid) update(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = tree[2 * at] + tree[2 * at + 1];
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if (lo > hi) return 0;
        push(at, lo, hi);
        if (from <= lo && hi <= to) return tree[at];
        ll total = 0;
        int mid = (lo + hi) >> 1;
        if (from <= mid) total += query(2 * at, lo, mid, from, to);
        if (to > mid) total += query(2 * at + 1, mid + 1, hi, from, to);
        return total;
    }
    ll query(int from, int to) {
        return query(1, 0, n - 1, from, to);
    }
    void update(int from, int to, ll val) {
        update(1, 0, n - 1, from, to, val);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    SegTree tree(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.update(i, i, x);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            tree.update(a, b, u);
        } else {
            int x;
            cin >> x;
            x--;
            cout << tree.query(x, x) << "\n";
        }
    }
}