#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Info {
    ll sum;
    ll ans;
    ll pref;
    ll suff;
    bool operator<(const Info& o) const {
        return ans < o.ans;
    };
};  

struct SegTree {
    int n;
    vector<Info> tree, lazy;
    SegTree(int n): tree(n*4+1), n(n+1), lazy(n*4+1) {}
    void update(int at, int lo, int hi, int from, int to, ll val){
        if(from <= lo && hi <= to){
            tree[at] = {val, val, val, val};
            return;
        }
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, val);

        auto left = tree[2*at];
        auto right = tree[2*at+1];

        auto& sum = tree[at].sum;
        auto& ans = tree[at].ans;
        auto& pref = tree[at].pref;
        auto& suff = tree[at].suff;

        sum = left.sum + right.sum;
        suff = max(right.suff, left.suff + right.sum);
        pref = max(left.pref, left.sum + right.pref);
        ans = max(left.ans, max(right.ans, left.suff + right.pref));
    }
    Info query(){
        return tree[1];
    }
    void update(int from, int to, ll val){
        update(1, 0, n-1, from, to, val);
    }
};

int main(){

    int n, m;
    cin >> n >> m;

    SegTree tree(n+10);

    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        tree.update(i, i, x);
    }

    cout << tree.query().ans << "\n";

    while(m--){
        ll i, val; cin >> i >> val;
        tree.update(i, i, val);
        cout << tree.query().ans << "\n";
    }
}