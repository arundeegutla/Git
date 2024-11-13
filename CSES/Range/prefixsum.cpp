#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1), lazy(n * 4 + 1) {}
    void push(int at) {
        tree[2 * at] += lazy[at];
        tree[2 * at + 1] += lazy[at];
        lazy[2 * at] += lazy[at];
        lazy[2 * at + 1] += lazy[at];
        lazy[at] = 0;
    }
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (lo > hi || hi < from || lo > to) return;
        if (from <= lo && hi <= to) {
            tree[at] += val;
            lazy[at] += val;
            return;
        }
        push(at);
        int mid = (lo + hi) >> 1;
        update(2 * at, lo, mid, from, to, val);
        update(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = max(tree[2 * at], tree[2 * at + 1]);
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if (lo > hi || hi < from || lo > to) return -1e18;
        if (from <= lo && hi <= to) return tree[at];
        push(at);
        int mid = (lo + hi) >> 1;
        return max(query(2 * at, lo, mid, from, to),
                   query(2 * at + 1, mid + 1, hi, from, to));
    }
    ll query(int from, int to) {
        return query(1, 0, n - 1, from, to);
    }
    void update(int from, int to, ll val) {
        update(1, 0, n - 1, from, to, val);
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    SegTree tree(n + 10);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        tree.update(i, i, sum);
    }

    auto print = [&]() -> void {
        for (int i = 0; i < n; i++) {
            cout << tree.query(i, i) << " ";
        }
        cout << "\n";
    };

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            ll diff = u - arr[k];
            tree.update(k, n - 1, diff);
            arr[k] = u;
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            int prev = (a == 0 ? 0 : tree.query(a - 1, a - 1));
            cout << max(0LL, tree.query(a, b) - prev) << "\n";
        }
    }
}
