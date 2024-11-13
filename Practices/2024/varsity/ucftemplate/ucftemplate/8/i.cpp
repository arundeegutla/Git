#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    unordered_map<int, multiset<int>> have;
    vector<int> tree;
    SegTree(int n) : tree(n * 4 + 1, 1e9), n(n + 1) {}
    void add(int at, int lo, int hi, int from, int to, int val) {
        if (lo > hi || hi < from || lo > to) return;
        if (from <= lo && hi <= to) {
            have[at].insert(val);
            tree[at] = *(have[at].begin());
            return;
        }
        int mid = (lo + hi) >> 1;
        add(2 * at, lo, mid, from, to, val);
        add(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = min(tree[2 * at], tree[2 * at + 1]);
    }
    void remove(int at, int lo, int hi, int from, int to, int val) {
        if (lo > hi || hi < from || lo > to) return;
        if (from <= lo && hi <= to) {
            have[at].erase(have[at].find(val));
            tree[at] = have[at].size() ? *(have[at].begin()) : 1e9;
            return;
        }
        int mid = (lo + hi) >> 1;
        remove(2 * at, lo, mid, from, to, val);
        remove(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = min(tree[2 * at], tree[2 * at + 1]);
    }
    int query(int at, int lo, int hi, int from, int to) {
        if (lo > hi || hi < from || lo > to) return 1e9;
        if (from <= lo && hi <= to) return tree[at];
        int mid = (lo + hi) >> 1;
        return min(query(2 * at, lo, mid, from, to),
                   query(2 * at + 1, mid + 1, hi, from, to));
    }
    int query(int from, int to) {
        return query(1, 0, n - 1, from, to);
    }
    void add(int ind, int val) {
        add(1, 0, n - 1, ind, ind, val);
    }
    void remove(int ind, int val) {
        remove(1, 0, n - 1, ind, ind, val);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    auto sorted = arr;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> id;
    for (int i = 0; i < n; i++)
        if (i == 0 || sorted[i] != sorted[i - 1]) id[sorted[i]] = id.size();
    for (auto& x : arr) x = id[x];

    auto solve = [&](int k) -> int {
        SegTree tree(id.size() + 50);
        vector<int> ans(n);

        ans[n - 1] = 0;
        tree.add(arr[n - 1], 0);
        for (int i = n - 2; i >= 0; i--) {
            if (i + k + 1 < n) {
                tree.remove(arr[i + k + 1], ans[i + k + 1]);
            }
            int up = tree.query(arr[i], id.size() + 2) + 1;
            int down = arr[i] - 1 >= 0 ? tree.query(0, arr[i] - 1) : 1e9;
            ans[i] = min(up, down);
            tree.add(arr[i], ans[i]);
        }

        return ans[0];
    };

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << solve(k) << "\n";
    }
}