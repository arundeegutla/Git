#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using info = pair<ll, ll>;



struct SegTree {
    int n;
    vector<info> tree, lazy;
    SegTree(int n): tree(n*4+1, {1e10, 1e10}), n(n+1), lazy(n*4+1) {}
    void update(int at, int lo, int hi, int from, int to, ll val){
        if(from <= lo && hi <= to){
            tree[at] = {val, 1};
            return;
        }
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, val);

        info left = tree[2*at];
        info right = tree[2*at+1];

        if(left.first == right.first) {
            tree[at] = {left.first, left.second + right.second};
        } else {
            tree[at] = min(left, right);
        }
    }
    info query(int at, int lo, int hi, int from, int to) {
        if(lo > hi) return {1e10, 1e10};
        if(from <= lo && hi <= to) return tree[at];
        info left = {1e10, 1e10};
        info right = {1e10, 1e10};

        int mid = (lo+hi)>>1;
        if(from <= mid) left = query(2*at, lo, mid, from, to);
        if(to > mid) right = query(2*at+1, mid+1, hi, from, to);

        if(left.first == right.first)
            return {left.first, left.second + right.second};

        return min(left, right);
    }
    info query(int from, int to){
        return query(1, 0, n-1, from, to);
    }
    void update(int from, int to, ll val){
        update(1, 0, n-1, from, to, val);
    }
};


int main(){
    int n, m; cin >> n >> m;
    SegTree tree(n+10);
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        tree.update(i, i, val);
    }

    while(m--){
        int q; cin >> q;
        int f; cin >> f;
        int s; cin >> s;

        if(q == 1) {
            tree.update(f, f, s);
        } else {
            auto [minn, count] = tree.query(f, s-1);
            cout << minn << " " << count << "\n";
        }
    }

}