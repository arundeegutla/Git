#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
// 1-based tree but 0-based range
struct SegTree {
    int n;
    vector<pair<int, ll>> tree;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1) {}
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (from <= lo && hi <= to) {
            tree[at].first = from;
            tree[at].second = val;
            return;
        }
        int mid = (lo + hi) >> 1;
        if (from <= mid) update(2 * at, lo, mid, from, to, val);
        if (to > mid) update(2 * at + 1, mid + 1, hi, from, to, val);

        if (tree[2 * at].second >= tree[2 * at + 1].second) {
            tree[at] = tree[2 * at];
        } else {
            tree[at] = tree[2 * at + 1];
        }
    }
    pair<int, ll> query(int at, int lo, int hi, ll val) {
        if (at >= tree.size() || lo > hi || tree[at].second < val) return {-1, -1};
        int mid = (lo + hi) >> 1;
        auto here1 = query(2 * at, lo, mid, val);
        if (here1.first != -1) return here1;

        auto here = query(2 * at + 1, mid + 1, hi, val);
        if (here.first != -1) return here;

        return tree[at];
    }
    pair<int, ll> query(ll val) {
        return query(1, 0, n - 1, val);
    }
    void update(int indx, ll val) {
        update(1, 0, n - 1, indx, indx, val);
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    SegTree tree(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.update(i, x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto here = tree.query(x);

        if (here.first == -1) {
            cout << 0 << " ";
            continue;
        }

        cout << here.first + 1 << " ";
        tree.update(here.first, here.second - x);
    }
    cout << "\n";
}