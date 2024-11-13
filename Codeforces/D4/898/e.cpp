#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;


    auto go = [&](ll height) -> ll {
        ll w = 0;
        for(auto x : arr) {
            w += max(0LL, height - x);
        } 
        return w;
    };

    ll lo = 1;
    ll hi = 1e10;
    ll ans = -1;
    while(lo <= hi) {
        ll mid = (lo+hi) >> 1;
        ll water = go(mid);

        if(water <= x) {
            lo = (ans = mid) + 1;
        } else 
            hi = mid - 1;

    }

    cout << ans << "\n";




}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}