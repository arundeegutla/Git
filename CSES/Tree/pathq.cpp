#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    vector<int> value(n);
    for (auto& x : value) cin >> x;

    vector<vector<int>> tree(n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> start(n), end(n);
    int timer = 0;
    function<void(int, int)> euler_tour = [&](int at, int prev) {
        start[at] = ++timer;
        for (auto e : tree[at])
            if (e != prev)
                euler_tour(e, at);
        end[at] = timer;
    };
    euler_tour(0, -1);

    vector<long long> path(n);
    function<void(int, int)> dfs = [&](int at, int prev) -> void {
        path[at] = (prev == -1 ? 0 : path[prev]) + value[at];
        for (auto e : tree[at]) {
            if (e != prev) {
                dfs(e, at);
            }
        }
    };
    dfs(0, -1);

    SegTree cumFreq(n + 10);
    for (int i = 0; i < n; i++)
        cumFreq.update(start[i], start[i], path[i]);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            int diff = x - value[s];
            cumFreq.update(start[s], end[s], diff);

            value[s] = x;
        } else {
            int s;
            cin >> s;
            s--;

            cout << cumFreq.query(start[s], start[s]) << "\n";
        }
    }
}