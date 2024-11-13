#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    using info = tuple<int, int, > int n;
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
}