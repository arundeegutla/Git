#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ll n;
    cin >> n;
    ll tot = (n * (n + 1)) / 2;
    if ((tot % 2) != 0) {
        cout << 0 << "\n";
        return 0;
    }
    ll half = tot / 2;

    ll MOD = 1e9 + 7;
    vector<vector<ll>> memo(n + 1, vector<ll>(half + 1));
    for (int i = 0; i <= n; i++) memo[i][0] = 1;
    for (int at = n - 1; at >= 1; at--) {
        for (int need = 1; need <= half; need++) {
            if (need - at < 0) continue;
            auto& ans = memo[at][need];
            ll ways = 0;
            ways += memo[at + 1][need - at];
            ways %= MOD;
            ways += memo[at + 1][need];
            ways %= MOD;
            ans = ways;
        }
    }

    cout << memo[1][half] << "\n";
}
