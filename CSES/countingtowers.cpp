#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[(int)1e6 + 1][1 << 5];
int main() {
    memset(memo, -1, sizeof(memo));
    int MOD = 1e9 + 7;
    function<ll(int, int)> go;
    go = [&](int floor, int prevMask) -> ll {
        if (floor == 0) {
            return 1;
        }
        auto& ans = memo[floor][prevMask + 1];
        if (ans != -1) return ans;

        ll ways = 0;
        if (prevMask == -1) {
            ways += go(floor - 1, 3);
            ways %= MOD;
            ways += go(floor - 1, 7);
            ways %= MOD;
        } else if ((prevMask & (1 << 2)) != 0) {
            // together before.
            ways += go(floor - 1, 4);
            ways %= MOD;
            ways += go(floor - 1, 3);
            ways %= MOD;
            ways += go(floor - 1, 7);
            ways %= MOD;
        } else {
            ways += go(floor - 1, 3);
            ways %= MOD;
            ways += go(floor - 1, 7);
            ways %= MOD;
            ways += go(floor - 1, 0);
            ways %= MOD;
            ways += go(floor - 1, 1);
            ways %= MOD;
            ways += go(floor - 1, 2);
            ways %= MOD;
        }

        return ans = ways;
    };

    /*
    11 -
    01
    10
    00
    11
    11
    11
    11

    */

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << go(n, -1) << "\n";
    }
}