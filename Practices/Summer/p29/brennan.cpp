#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int MOD = (int) 1e9 + 7;

int go(int n, int bits, int k, vector<int> &arr, vector<vector<ll>> &dp) {
    if (bitset<10>(bits).count() < k) return 0;
    if (n == arr.size()) return bitset<10>(bits).count() == k ? 1 : 0;
    if (dp[n][bits] != -1) return dp[n][bits];

    ll take = go(n + 1, bits & arr[n], k, arr, dp) % MOD;
    ll leave = go(n + 1, bits, k, arr, dp) % MOD;

    return dp[n][bits] = (take % MOD) + (leave % MOD) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        rep(i, 0, n) cin >> arr[i];
        vector<vector<ll>> dp(n, vector<ll>(128, -1));
        cout << go(0, 127, k, arr, dp) % MOD << endl;
    }

    return 0;
}
