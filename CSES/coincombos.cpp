#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[(int)1e6 + 1];

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    int MOD = 1e9 + 7;
    memo[0] = 1;
    for (int at = n - 1; at >= 0; at--) {
        for (int need = 0; need <= x; need++) {
            if (need - arr[at] >= 0) {
                memo[need] += memo[need - arr[at]];
                memo[need] %= MOD;
            }
        }
    }

    cout << memo[x] << "\n";
}
