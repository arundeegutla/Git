#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree(int n): tree(n*4+1), n(n+1), lazy(n*4+1) {}
    void lazyProcess(int at){
        tree[2*at] += lazy[at];
        tree[2*at+1] += lazy[at];
        lazy[2*at] += lazy[at];
        lazy[2*at+1] += lazy[at];
        lazy[at] = 0;
    }
    void update(int at, int lo, int hi, int from, int to, ll val){
        if(from <= lo && hi <= to){
            tree[at] += val;
            lazy[at] += val;
            return;
        }
        lazyProcess(at);
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, val);
        tree[at] = tree[2*at] + tree[2*at+1];
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if(lo > hi) return 0;
        if(from <= lo && hi <= to) return tree[at];
        lazyProcess(at);
        ll total = 0;
        int mid = (lo+hi)>>1;
        if(from <= mid) total += query(2*at, lo, mid, from, to);
        if(to > mid) total += query(2*at+1, mid+1, hi, from, to);
        return total;
    }
    ll query(int from, int to){
        return query(1, 0, n-1, from, to);
    }
    void update(int from, int to, ll val){
        update(1, 0, n-1, from, to, val);
    }
};

// check for int overflow.
void solve() {
    cout << UINT64_MAX << " " << LLONG_MAX << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}