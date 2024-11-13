#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e6 + 1;
int dp[MAX];

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    int MOD = 1e9 + 7;
    auto go = [&](int need, auto&& go) -> ll {
        if (need < 0) return 0;
        if (need == 0) return 1;
        auto& ans = dp[need];
        if (ans != -1) {
            return ans;
        }
        ll ways = 0;
        for (int i = 1; i <= 6; i++) {
            ways += go(need - i, go);
            ways %= MOD;
        }
        return ans = ways;
    };

    cout << go(n, go) << "\n";
}