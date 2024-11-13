#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[505][(int)7e4];
int main() {
    memset(memo, -1, sizeof(memo));
    ll n;
    cin >> n;
    ll tot = (n * (n + 1)) / 2;
    if ((tot % 2) != 0) {
        cout << 0 << "\n";
        return 0;
    }
    ll half = tot / 2;

    int MOD = 1e9 + 7;
    function<ll(int, ll)> go;
    go = [&](int at, ll need) -> ll {
        if (at > n + 1) return 0;
        if (need < 0) return 0;
        if (need == 0) return 1;
        auto& ans = memo[at][need];
        // if (ans != -1) return ans;
        ll ways = 0;
        ways += go(at + 1, need - at);
        ways %= MOD;
        ways += go(at + 1, need);
        ways %= MOD;
        return ans = ways;
    };

    cout << go(1, half) / 2 << "\n";
}