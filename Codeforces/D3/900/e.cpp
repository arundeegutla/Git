#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
ll DEFAULT = (1LL<<31)-1;

struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int n): tree(n*4+1, DEFAULT), n(n+1) {}
    void update(int at, int lo, int hi, int from, int to, ll val){
        if(from <= lo && hi <= to){
            tree[at] = val;
            return;
        }
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, val);

        tree[at] = tree[2*at] & tree[2*at+1];
    }

    ll query(int at, int lo, int hi, int from, int to) {
        if(lo > hi) return DEFAULT;
        if(from <= lo && hi <= to) return tree[at];
        ll AND = DEFAULT;
        int mid = (lo+hi)>>1;
        if(from <= mid) AND &= query(2*at, lo, mid, from, to);
        if(to > mid) AND &= query(2*at+1, mid+1, hi, from, to);
        return AND;
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
    SegTree tree(n+10);


    ll tot = DEFAULT;
    for(int i = 0; i < n; i++){
        auto& x = arr[i];
        cin >> x;
        tree.update(i, i, arr[i]);
        tot &= x;
    } 

    // Find R that is >= L.
    // AND of L-R >= K

    


    int q;
    cin >> q;
    while(q--){

        int l, k;
        cin >> l >> k;
        l--;

        int lo = l;
        int hi = n-1;
        int ans = -2;
        while(lo <= hi) {
            int mid = (lo+hi) >> 1;
            auto AND = tree.query(l, mid);

            // ll actual = DEFAULT;
            // for(int i = l; i <= mid; i++){
            //     actual &= arr[i];
            // }

            // cout << l << "->" << mid << " " << n << " " << actual << " " << AND << "\n";


            if(AND >= k) {
                lo = (ans = mid) + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans+1 << " ";
    }

    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}