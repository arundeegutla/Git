#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1), lazy(n * 4 + 1) {}
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (from <= lo && hi <= to) {
            tree[at] += val;
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
        ll total = 0;
        int mid = (lo + hi) >> 1;
        if (from <= mid) total = query(2 * at, lo, mid, from, to);
        if (to > mid) total = max(total, query(2 * at + 1, mid + 1, hi, from, to));
        return total;
    }
    ll query(int from, int to) {
        return query(1, 0, n - 1, from, to);
    }
    void update(int from, int to, ll val) {
        update(1, 0, n - 1, from, to, val);
    }
};

struct DS {
    vi size, parent;
    vvi weights, indices;
    DS(int n) : size(n, 1), parent(n), weights(n), indices(n) {
        for (int i = 0; i < n; i++) indices[i].push_back(i);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void merge(int a, int b, ll amt) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        weights[a].push_back(amt);
        for (auto& x : weights[b]) weights[a].push_back(x);
        for (auto& x : indices[b]) indices[a].push_back(x);
        weights[b].clear();
        indices[b].clear();
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<ll, pair<int, int>>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        edges.push_back({t, {u, v}});
    }
    sort(edges.begin(), edges.end());

    DS dsu(n);
    for (auto& [w, e] : edges)
        dsu.merge(e.first, e.second, w);

    int root = dsu.find(0);
    vi mstEdges = dsu.weights[root];
    vi id(n);
    for (int i = 0; i < n; i++)
        id[dsu.indices[root][i]] = i;

    SegTree tree(n);
    for (int i = 0; i < n - 1; i++)
        tree.update(i, i, mstEdges[i]);

    auto getHi = [&](int a, ll maxx) -> int {
        int lo = a + 1;
        int hi = n - 1;
        int ans = a;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            ll here = tree.query(a, mid - 1);
            if (here <= maxx) {
                lo = (ans = mid) + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    };

    auto getLow = [&](int a, ll maxx) -> int {
        int lo = 0;
        int hi = a - 1;
        int ans = a;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            ll here = tree.query(mid, a);
            if (here <= maxx) {
                hi = (ans = mid) - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    };

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        a = id[a], b = id[b];
        if (a > b) swap(a, b);
        ll maxx = tree.query(a, b - 1);
        int lat = getLow(a, maxx);
        int rat = getHi(a, maxx);
        cout << maxx << " " << rat - lat + 1 << "\n";
    }
}
