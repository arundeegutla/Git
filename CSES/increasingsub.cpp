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
    SegTree(int n): tree(n*4+1), n(n+1), lazy(n*4+1) {}
    void update(int at, int lo, int hi, int from, int to, ll val){
        if(from <= lo && hi <= to){
            tree[at] = max(tree[at], val);
            return;
        }
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, val);
        tree[at] = max(tree[2*at], tree[2*at+1]);
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if(lo > hi) return 0;
        if(from <= lo && hi <= to) return tree[at];
        ll maxx = 0;
        int mid = (lo+hi)>>1;
        if(from <= mid) maxx = max(maxx, query(2*at, lo, mid, from, to));
        if(to > mid) maxx = max(maxx, query(2*at+1, mid+1, hi, from, to));
        return maxx;
    }
    ll query(int from, int to){
        return query(1, 0, n-1, from, to);
    }
    void update(int from, int to, ll val){
        update(1, 0, n-1, from, to, val);
    }
};



void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;


    set<int> ordered(all(arr));
    unordered_map<int, int> hmap;
    for(auto x : ordered)
        hmap[x] = hmap.size() + 1;

    auto newArr = arr;
    for(auto& x : newArr)
        x = hmap[x];

    SegTree tree(ordered.size()+10);

    for(auto x : newArr) {
        int ans = tree.query(0, x-1) + 1;
        tree.update(x, x, ans);
    }

    cout << tree.query(0, ordered.size()+2) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}