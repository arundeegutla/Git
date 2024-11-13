#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2][5001][5001];
int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    function<ll(int, int, int)> go;
    go = [&](int turn, int l, int r) -> ll {
        if (l > r) return 0;
        auto& ans = dp[turn][l][r];
        if (ans != -1) return ans;
        if (turn) {
            ll takeL = go(!turn, l + 1, r) + arr[l];
            ll takeR = go(!turn, l, r - 1) + arr[r];
            return ans = max(takeL, takeR);
        } else {
            ll takeL = go(!turn, l + 1, r);
            ll takeR = go(!turn, l, r - 1);
            return ans = min(takeL, takeR);
        }
    };

    cout << go(1, 0, n - 1) << "\n";
}