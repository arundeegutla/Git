#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int n) : tree(n * 4 + 1), n(n + 1) {}
    void update(int at, int lo, int hi, int from, int to, ll val) {
        if (lo > hi || hi < from || lo > to) return;
        if (from <= lo && hi <= to) {
            tree[at] += val;
            return;
        }
        int mid = (lo + hi) >> 1;
        update(2 * at, lo, mid, from, to, val);
        update(2 * at + 1, mid + 1, hi, from, to, val);
        tree[at] = tree[2 * at] + tree[2 * at + 1];
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if (lo > hi || hi < from || lo > to) return 0;
        if (from <= lo && hi <= to) return tree[at];
        int mid = (lo + hi) >> 1;
        return query(2 * at, lo, mid, from, to) +
               query(2 * at + 1, mid + 1, hi, from, to);
    }
    ll query(int from, int to) {
        return query(1, 0, n - 1, from, to);
    }
    void update(int from, int to, ll val) {
        update(1, 0, n - 1, from, to, val);
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    auto sorted = arr;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> id;
    for (auto& x : sorted)
        if (!id.count(x))
            id[x] = id.size();

    vector<int> num(id.size());
    for (auto [x, i] : id)
        num[i] = x;

    SegTree tree(id.size() + 10);
    for (int i = 0; i < k; i++) {
        int place = id[arr[i]];
        tree.update(place, place, 1);
    }

    vector<int> ans;
    auto getMedian = [&]() -> void {
        int targetPos = (k + 1) / 2;
        int lo = 0;
        int hi = id.size() - 1;
        int ansId = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int numElements = tree.query(0, mid);
            if (numElements >= targetPos) {
                hi = (ansId = mid) - 1;
            } else {
                lo = mid + 1;
            }
        }
        // cout << targetPos << " " << ansId << " " << tree.query(0, ansId) << " " << tree.query(0, id.size()) << "\n";
        ans.push_back(num[ansId]);
    };

    getMedian();
    for (int i = k; i < n; i++) {
        int prev = id[arr[i - k]];
        tree.update(prev, prev, -1);
        int place = id[arr[i]];
        tree.update(place, place, 1);
        getMedian();
    }

    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
}