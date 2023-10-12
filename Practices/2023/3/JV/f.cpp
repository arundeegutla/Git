#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    vector<ll> transactions(n);
    for(auto& x : transactions) cin >> x;


    auto can = [&](ll start) -> bool {
        ll cur = start;
        for(auto x : transactions) {
            cur += x;
            if(cur < 0) return false;
        }  
        return true;
    };


    ll lo = 0;
    ll hi = 1e10;
    ll ans = -1;
    while(lo <= hi){
        ll mid = (lo+hi) >> 1;
        if(can(mid)) {
            hi = (ans = mid) - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}