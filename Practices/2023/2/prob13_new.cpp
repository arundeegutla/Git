#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

struct SegTree {
    int n;
    vector<ll> tree, lazy;
    SegTree(int n): tree(n*4+1), n(n+1), lazy(n*4+1) {}
    void update(int at, int lo, int hi, int from, int to, ll val){
        if(from <= lo && hi <= to){
            tree[at] += val;
            lazy[at] += val;
            return;
        }
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, val);
        tree[at] = tree[2*at] + tree[2*at+1];
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if(lo > hi) return 0;
        if(from <= lo && hi <= to) return tree[at];
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


void solve() {
    
    int q;
    cin >> q;
    queue<pair<int, pair<string, int>>> queries;
    unordered_map<string, vector<string>> tree;

    while(q--){
        string type;
        cin >> type;
        if(type == "ADD"){
            string par, name;
            cin >> par >> name;
            tree[par].push_back(name);
            
        } else if(type == "SALE"){
            string emp; ll x;
            cin >> emp >> x;
            queries.push({0, {emp, x}});
        } else {
            string name;
            cin >> name;
            queries.push({1, {name, -1}});
        }
    }




}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "COMPANY " << i << "\n";
        solve();
    }
}