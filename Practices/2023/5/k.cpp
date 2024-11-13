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
    vector<ll> tree;
    SegTree(int n): tree(n*4+1, 1e10), n(n+1) {}
    void update(int at, int lo, int hi, int from, int to, ll val){
        if(from <= lo && hi <= to){
            tree[at] = min(tree[at], val);
            return;
        }
        int mid = (lo + hi) >> 1;
        if(from <= mid) update(2*at, lo, mid, from, to, val);
        if(to > mid) update(2*at+1, mid+1, hi, from, to, val);
        tree[at] = min(tree[2*at], tree[2*at+1]);
    }
    ll query(int at, int lo, int hi, int from, int to) {
        if(lo > hi) return 1e10;
        if(from <= lo && hi <= to) return tree[at];
        ll minn = 1e10;
        int mid = (lo+hi)>>1;
        if(from <= mid) minn = min(minn, query(2*at, lo, mid, from, to));
        if(to > mid) minn = min(minn, query(2*at+1, mid+1, hi, from, to));
        return minn;
    }
    ll query(int from, int to){
        return query(1, 0, n-1, from, to);
    }
    void update(int from, int to, ll val){
        update(1, 0, n-1, from, to, val);
    }
};


void solve() {
    int MAX = 1e6;
    ll s, t, n;
    cin >> s >> t >> n;

    SegTree tree(MAX+10);
    while(n--){
        int avg, time;
        cin >> avg >> time;
        tree.update(avg, avg, time);
    }

    if(s < t) {
        cout << -1 << "\n";
        return;
    }

    if(s == t) {
        cout << 0 << "\n";
        return;
    }

    double curAvg = s;
    double targetAvg = t;
    double time = 0;

    while(curAvg > targetAvg) {
        ll fastestSpeed = tree.query(curAvg, MAX);
        if(fastestSpeed > MAX) {
            cout << -1 << "\n";
            return;
        }
        // cant halve it anymore.
        if(curAvg < targetAvg * 2) {
            double x = targetAvg / curAvg;
            time += (fastestSpeed * 2) * x;
            cout << curAvg << " " << (fastestSpeed * 2) * x << " " << x << "\n";
            curAvg = targetAvg;
        } else {
            curAvg /= 2;
            time += fastestSpeed;
            cout << curAvg << " " << fastestSpeed << "\n";

        }
    }


    cout << fixed << setprecision(10) << time << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}