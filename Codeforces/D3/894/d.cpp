#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    ll n; cin >> n;

    ll lo = 0;
    ll hi = 2648956421;
    ll ans = -1;
    while(lo <= hi){
        ll mid = (lo+hi) >> 1;
        ll diffTypes = (mid*(mid-1)) >> 1;

        if(diffTypes <= n){
            lo = (ans = mid) + 1;
        } else {
            hi = mid - 1;
        }
    }

    ll diffTypes = (ans*(ans-1)) >> 1;
    cout << ans + (n-diffTypes) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}