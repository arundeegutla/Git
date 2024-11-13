#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> time(n);
    for (auto& x : time) cin >> x;

    auto count = [&](ll second) -> bool {
        ll here = 0;
        for (auto x : time) {
            here += second / x;
            if (here >= t) return true;
        }
        return false;
    };

    ll lo = 0;
    ll hi = 1e18;
    ll ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (count(mid)) {
            hi = (ans = mid) - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}