#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int memo[103][(int)1e5 + 1];

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    int MOD = 1e9 + 7;

    auto getSum = [&](int row, int hi, int lo) -> ll {
        ll ans = memo[row][hi] - (lo == 0 ? 0 : memo[row][lo - 1]);
        if (ans < 0) ans += MOD;
        ans %= MOD;
        return ans;
    };

    memo[n][0] = 1;
    for (int at = n - 1; at >= 0; at--) {
        for (int have = 0; have <= k; have++) {
            memo[at][have] = getSum(at + 1, have, have - min(have, arr[at]));
        }
        for (int i = 1; i <= k; i++) {
            memo[at][i] += memo[at][i - 1];
            memo[at][i] %= MOD;
        }
    }
    cout << memo[0][k] << "\n";
}