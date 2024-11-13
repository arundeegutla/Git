#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1), lazy(n * 4 + 1) {}
    void lazyProcess(int at) {
        tree[2 * at] += lazy[at];
        tree[2 * at + 1] += lazy[at];
        lazy[2 * at] += lazy[at];
        lazy[2 * at + 1] += lazy[at];
        lazy[at] = 0;
    }
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (from <= lo && hi <= to) {
            tree[at] += val;
            lazy[at] += val;
            return;
        }
        lazyProcess(at);
        int mid = (lo + hi) >> 1;
        if (from <= mid) update(2 * at, lo, mid, from, to, val);
        if (to > mid) update(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = tree[2 * at] + tree[2 * at + 1];
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if (lo > hi) return 0;
        if (from <= lo && hi <= to) return tree[at];
        lazyProcess(at);
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

SegTree tree(4e5 + 10);

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    for (auto& x : pairs) {
        cin >> x.first;
        cin >> x.second;
    }
    sort(pairs.begin(), pairs.end());

    set<int> allNums;
    for (auto [a, b] : pairs) {
        allNums.insert(a);
        allNums.insert(b);
    }

    map<int, int> id;
    for (auto x : allNums) {
        id[x] = id.size();
    }

    ll tot = 0;

    for (auto [a, b] : pairs) {
        tree.update(id[b], id[b], 1);
    }

    for (auto [a, b] : pairs) {
        tot += tree.query(id[a], id[b]) - 1;
        tree.update(id[b], id[b], -1);
    }

    cout << tot << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}