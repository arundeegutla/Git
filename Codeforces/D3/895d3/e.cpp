#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
using info = array<ll, 2>;

info operator^(const info& a, const info& b) {
    return {a[0]^b[0], a[1]^b[1]};
}

struct SegTree {
    int n;
    vector<info> tree;
    vector<int> lazy;

    SegTree(int n): tree(n*4+1), n(n+1), lazy(n*4+1) {}

    void lazyProcess(int at){
        if(lazy[at]){
            swap(tree[at*2][0], tree[at*2][1]);
            lazy[2*at] = 1;
            swap(tree[at*2+1][0], tree[at*2+1][1]);
            lazy[2*at+1] = 1;
            lazy[at] = 0;
        }
    }
    void update(int at, int lo, int hi, int from, int to, ll num, int val){
        if(from <= lo && hi <= to){
            swap(tree[at][0], tree[at][1]);
            lazy[at] = 1;
            if(val != -1) tree[at][val] = num;
            return;
        }
        lazyProcess(at);
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, num, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, num, val);
        tree[at] = tree[2*at] ^ tree[2*at+1];
    }

    info query(int at, int lo, int hi, int from, int to) {
        if(lo > hi) return {0, 0};
        lazyProcess(at);
        if(from <= lo && hi <= to) return tree[at];
        info total = {0, 0};
        int mid = (lo+hi)>>1;
        if(from <= mid) total = total ^ query(2*at, lo, mid, from, to);
        if(to > mid) total = total ^ query(2*at+1, mid+1, hi, from, to);
        return total;
    }
    info query(int from, int to){
        return query(1, 0, n-1, from, to);
    }
    void update(int from, int to, ll num, int val){
        update(1, 0, n-1, from, to, num, val);
    }
};


void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;
    string s; cin >> s;

    SegTree tree(n+10);
    for(int i = 0; i < n; i++){
        tree.update(i, i, arr[i], s[i]-'0');
    }

    int c; cin >> c;
    while(c--){
        int q; cin >> q;
        if(q == 1){
            int l, r;
            cin >> l >> r;
            tree.update(l-1, r-1, -1, -1);
        } else {
            int val; cin >> val;
            cout << tree.query(0, n)[val] << " ";
        }
    }
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}