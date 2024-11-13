#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
using ll = long long;

// 1-based tree but 0-based range
struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1) {}
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (from <= lo && hi <= to) {
            tree[at] += val;
            return;
        }
        int mid = (lo + hi) >> 1;
        if (from <= mid) update(2 * at, lo, mid, from, to, val);
        if (to > mid) update(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = tree[2 * at] + tree[2 * at + 1];
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if (lo > hi) return 0;
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
    void update(int from, ll val) {
        update(1, 0, n - 1, from, from, val);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    vector<int> allNums = arr;
    queue<pair<char, pair<int, int>>> q;
    while (m--) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        allNums.push_back(c);

        if (a != '!')
            allNums.push_back(b);

        q.push({a, {b, c}});
    }

    unordered_set<int> hset(allNums.begin(), allNums.end());
    vector<int> sorted;
    for (auto x : hset)
        sorted.push_back(x);
    sort(sorted.begin(), sorted.end());

    unordered_map<int, int> id;
    for (auto& x : sorted)
        id[x] = id.size() + 1;

    SegTree tree(id.size() + 1);

    for (auto& x : arr) {
        x = id[x];
        tree.update(x, 1);
    }

    while (q.size()) {
        auto [t, info] = q.front();
        q.pop();
        if (t == '!') {
            tree.update(arr[info.first - 1], -1);
            arr[info.first - 1] = id[info.second];
            tree.update(arr[info.first - 1], 1);
        } else {
            cout << tree.query(id[info.first], id[info.second]) << "\n";
        }
    }
}
