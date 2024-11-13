#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;

int n;
ll dp[MAXN][MAXN];

ll go(int l, int r) {
    if (dp[l][r] > -1)
        return dp[l][r];

    if (!(l && r))
        return (dp[l][r] = dp[r][l] = 1);

    ll res = go(l - 1, r) + go(l, r - 1);

    return (dp[l][r] = (res % MOD));
}

ll solve() {
    memset(dp, -1, sizeof(dp));

    ll res = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int left = j - i - 1;
            int right = n - left - 2;
            res += go(left, right);
            res %= MOD;
        }
    }

    return res;
}

int main() {
    cin >> n;
    cout << solve() << endl;
}